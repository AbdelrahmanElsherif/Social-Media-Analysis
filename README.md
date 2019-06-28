<h1 align="center"> Social Media Analysis Application </h1> <br>
<p align="center">
    <img alt="SM Analysis" title="SM Analysis" src="http://i65.tinypic.com/29nt9fo.jpg">
  </a>
</p>

### Introduction 

<p>
The project aims at applying algorithms based on graph theory to compute the centrality property for each node in the graph. Definition of ‘central’ varies by context/purpose. However, the main aim is to give a score to each node. This score is used to determine the most important nodes in the graph. These techniques are used in social media analysis to determine the set of influencers out of a graph containing millions of users and connections. Centrality has many definitions. Each definition gives scores to nodes in different ways. You are asked to implement three centrality metrics on undirected connected graphs.</p>


### Installation Steps (for development)

1- Download an IDE of our choice
2- Download Graphviz for windows:
    a. Download the installer from this <a href="https://graphviz.gitlab.io/_pages/Download/Download_windows.html" target="_blank">link</a>
    b. The default installation path will be C:\Program Files (x86)\GraphvizX.XX\bin (Example: GraphvizX.XX → Graphviz2.38)
    c. Open cmd window as administrator and go the location C:\Program Files (x86)\GraphvizX.XX\bin and run the below command:
          <b>dot.exe</b>
    d. Exit the command window.
    e. Go to the Control Panel →  System and Security → System, and on the right side navigation panel, you will see the link Advanced          systems settings.
    f. Once there in advance settings, a dialogue box will open which will show the button Environment Variables. Click on the button          Environment Variables.
    g. Select the entry "Path" on the system variables section and add C:\Program Files (x86)\GraphvizX.XX\bin to the existing path.            Please see this <a href="https://bobswift.atlassian.net/wiki/download/thumbnails/20971549/system_variable.png?version=1&modificationDate=1552911615663&cacheVersion=1&api=v2&width=400&height=315" target="_blank">screenshot</a> and <a href="https://bobswift.atlassian.net/wiki/download/thumbnails/20971549/sys_variable.png?version=1&modificationDate=1552911641477&cacheVersion=1&api=v2&width=400&height=303" target="_blank">this</a> for reference.
       <i>Note: Please make sure you add ";" at the PATH which is already existing under User Variables and mention the path C:\Program          Files (x86)\GraphvizX.XX\bin. Also please add a New path on the system variables section and add the Path C:\Program Files              (x86)\GraphvizX.XX\bin</i>
    h. Click on Ok Button. 
    i. Restart Confluence from a new cmd window.
    j. Go to the system information page on confluence instance.
    k. Verify if you can see C:\Program Files (x86)\GraphvizX.XX\bin on "Path" attribute on system information page in confluence.
    l. If the path is available, that means that the configuration changes are successful.
    m. Go the page where you have used the macro and verify if the add-ons work.
    n. Restart Confluence.
3- Make sure to put the source code you desire from this project in your project folder. (ex: degree_centerality)
4- Add the cppbatch_main.bat file in your main C++ project folder.
5- You are good to go!
       
### Helpful Links (Graphviz & Dot Language guides)
- https://bobswift.atlassian.net/wiki/spaces/GVIZ/pages/20971549/How+to+install+Graphviz+software
- http://www.drdobbs.com/cpp/graphviz-and-c/184402049
- https://graphs.grevian.org/example#example-1
- https://www.graphviz.org/doc/info/shapes.html





