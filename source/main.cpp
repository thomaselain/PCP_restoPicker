#include <general.hpp>

int logFatalError(string message)
{
  cout << message << endl;
  return -1;
}

int main()
{
  json file;
  map<string, pair<double, double> > ll_restos;
  double total = 0, backup, to_add;

  srand(time(0));
  ifstream i("restos.json");
  i >> file;

  for ( json::iterator it = file["restos"].begin(); it != file["restos"].end(); ++it )
  {
    if ( (*it)["nom"].empty() )
      return logFatalError("Il manque un nom, putos.");
    if ( (*it)["note"].empty() )
      return logFatalError("Il manque la note, putos.");
    backup = total;
    to_add = (*it)["note"];
    total += to_add;
    ll_restos[(*it)["nom"]] = pair<double, double>(backup, total);
  }

  double res = rand() % (int)total;

  for ( map<string, pair<double, double> >::iterator it = ll_restos.begin(); it != ll_restos.end(); ++it )
  {
    if ( res > (*it).second.first && res < (*it).second.second )
    {
      cout << (*it).first << " est le grand vainqueur !"  << endl;
      return 0;
    }
  }

  return -1;
}
