from django.shortcuts import render, get_object_or_404
from django.http import Http404
import datetime
from django.utils import timezone
from django.template import RequestContext,loader
from django.http import HttpResponse, HttpResponseRedirect
from django.core.urlresolvers import reverse
from django.views import generic
from .models import Question, Choice


class IndexView(generic.ListView):
    template_name = 'polls/index.html'
    context_object_name = 'latest_question_list'
    def get_queryset(self):
    	"""Return the last five published questions"""
    	return Question.objects.filter(pub_date__lte=timezone.now()).order_by('-pub_date')[:5]

class DetailView(generic.DetailView):
	model = Question
	template_name = 'polls/detail.html'

class ResultsView(generic.DetailView):
	model = Question
	template_name = 'polls/results.html'

def vote(request, question_id):
	p = get_object_or_404(Question, pk=question_id)
	try:
		selected_choice = p.choice_set.get(pk=request.POST['choice'])
	except(KeyError, Choice.DoesNotExist):
		return render(request, 'polls/detail.html', {'question': p, 'error_message': "You didn't select a choice."})

	else:
		selected_choice.votes +=1
		selected_choice.save()
		#Y tenemos que mostrar algo por pantalla para hacer un render y que asi el usuario no haga lo de volver atras
		return HttpResponseRedirect(reverse('polls:results', args=(p.id,)))