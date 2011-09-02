<map version="0.9.0">
<!--To view this file, download free mind mapping software Freeplane from http://freeplane.sourceforge.net -->
<node TEXT="Discussion sur le cadre logiciel" ID="ID_324627559" CREATED="1314824342775" MODIFIED="1314824353088">
<hook NAME="MapStyle" max_node_width="600"/>
<node TEXT="De quoi on parle ici ?" POSITION="right" ID="ID_1010821014" CREATED="1314824354493" MODIFIED="1314824405726">
<node TEXT="Le logiciel support des lemmings" ID="ID_1068750936" CREATED="1314824407061" MODIFIED="1314824417547"/>
<node TEXT="L&apos;interface g&#xe9;n&#xe9;rale" ID="ID_1968727222" CREATED="1314824417845" MODIFIED="1314824424429"/>
<node TEXT="Les solutions pour la mettre en place" ID="ID_955859605" CREATED="1314824424711" MODIFIED="1314824434051"/>
<node TEXT="En partie, les probl&#xe8;mes qu&apos;on rencontre au fil du temps" ID="ID_412217952" CREATED="1314969819099" MODIFIED="1314969831397"/>
</node>
<node TEXT="Id&#xe9;es pr&#xe9;-con&#xe7;ues" POSITION="right" ID="ID_66298223" CREATED="1314824435673" MODIFIED="1314824442886">
<node TEXT="1&#xb0;" ID="ID_1788178852" CREATED="1314824445625" MODIFIED="1314824447956">
<node TEXT="Ce que j&apos;avais fait avant qu&apos;on arr&#xea;te d&apos;en parler" ID="ID_964874373" CREATED="1314824448787" MODIFIED="1314824461203"/>
<node TEXT="Une fen&#xea;tre Windows (avec le fond gris)" ID="ID_178517391" CREATED="1314824463896" MODIFIED="1314824480103"/>
<node TEXT="avec des boutons au choix" ID="ID_1237176554" CREATED="1314824480321" MODIFIED="1314824485526"/>
<node TEXT="des raccourcis claviers" ID="ID_617406334" CREATED="1314824486067" MODIFIED="1314824490709"/>
<node TEXT="des menus" ID="ID_393814659" CREATED="1314824490955" MODIFIED="1314824493822"/>
<node TEXT="pas de fullscreen" ID="ID_541778570" CREATED="1314824494611" MODIFIED="1314824497784"/>
<node TEXT="resizable" ID="ID_1094051281" CREATED="1314824498068" MODIFIED="1314824500501"/>
<node TEXT="une sous fen&#xea;tre centr&#xe9;e qui accueille la partie SDL" ID="ID_1836028188" CREATED="1314824500785" MODIFIED="1314824517698"/>
<node TEXT="avec un curseur SDL" ID="ID_405025371" CREATED="1314824517952" MODIFIED="1314824536141"/>
<node TEXT="une file de message SDL" ID="ID_932686032" CREATED="1314824536386" MODIFIED="1314824542090"/>
<node TEXT="structure au niveau de la programmation" ID="ID_1656532839" CREATED="1314824550662" MODIFIED="1314824566840">
<node TEXT="2 threads" ID="ID_1353344857" CREATED="1314824567619" MODIFIED="1314824572175">
<node TEXT="un main : il fait le dispatch des messages pour la fen&#xea;tre Windows" ID="ID_856366943" CREATED="1314824577269" MODIFIED="1314824594007"/>
<node TEXT="un sdl : il fait le frameDraw, et le dispatch des messages SDL" ID="ID_796535459" CREATED="1314824594440" MODIFIED="1314824618050"/>
</node>
<node TEXT="le son est g&#xe9;r&#xe9; par le main" ID="ID_1020376469" CREATED="1314824621946" MODIFIED="1314824647416"/>
<node TEXT="la couche SDL n&apos;est pas initi&#xe9;e au d&#xe9;marrage (surement pour des raisons de tests)" ID="ID_1953335358" CREATED="1314824655860" MODIFIED="1314824679299"/>
<node TEXT="la partie SDL, bien qu&apos;int&#xe9;gr&#xe9;e dans la partie Windows, est isol&#xe9;e" ID="ID_195988472" CREATED="1314824680538" MODIFIED="1314824697375"/>
<node TEXT="il y a des int&#xe9;ractions entre les 2 parties, cf avantages et inconv&#xe9;nienst" ID="ID_586813875" CREATED="1314824697922" MODIFIED="1314824729491"/>
</node>
<node TEXT="avantages" ID="ID_1527801779" CREATED="1314824731936" MODIFIED="1314824735112">
<node TEXT="utilisation des menus, raccourcis claviers, des boutons windows (toue l&apos;interface Windows dispo autour de SDL)" ID="ID_1875914248" CREATED="1314824735374" MODIFIED="1314824836408"/>
<node TEXT="pas &#xe0; g&#xe9;rer le fullscreen, resizable easy" ID="ID_813123984" CREATED="1314824792200" MODIFIED="1314824798337"/>
<node TEXT="peut-&#xea;tre des facilit&#xe9;s quand il y aura la partie multijoueur car la fen&#xea;tre Windows permet d&apos;accueillir des messages de type : quelqu&apos;un essaie de se connecter... (argument &#xe0; laisser de c&#xf4;t&#xe9;)" ID="ID_434926679" CREATED="1314824838061" MODIFIED="1314824887021"/>
<node TEXT="on peut poper des fen&#xea;tres windows, c&apos;est cool aussi, car on a tous les controles Windows (les boutons, les edit, les checkbox, les IPbox, ...)" ID="ID_1793670538" CREATED="1314824984903" MODIFIED="1314825024413"/>
<node TEXT="pas besoin d&apos;interface dans le jeu car elle est autour" ID="ID_1403384256" CREATED="1314825115535" MODIFIED="1314825144626"/>
<node TEXT="Pour ce qui est de l&apos;interface pendant le jeu (click souris), il y a les messages SDL, c&apos;est ok" ID="ID_155997290" CREATED="1314824971339" MODIFIED="1314825042944"/>
</node>
<node TEXT="inconv&#xe9;nients" ID="ID_465940472" CREATED="1314824895926" MODIFIED="1314824904206">
<node TEXT="(temporaire surement) threads : c&apos;est beau, mais &#xe7;a veut dire partage de ressources, et &#xe7;a c&apos;est casse bonbons" ID="ID_1676186260" CREATED="1314824900745" MODIFIED="1314824958739"/>
<node TEXT="communication couche windows &lt;-&gt; couche SDL (sans parler du partage de ressources)" ID="ID_102632888" CREATED="1314825050003" MODIFIED="1314825080665"/>
<node TEXT="pas de fullscreen" ID="ID_47489691" CREATED="1314825095502" MODIFIED="1314825099678"/>
</node>
</node>
<node TEXT="2&#xb0;" ID="ID_61499380" CREATED="1314878124474" MODIFIED="1314878126949">
<node TEXT="Bien copi&#xe9; du premier" ID="ID_75728741" CREATED="1314878127094" MODIFIED="1314878143741"/>
<node TEXT="fenetre windows avec ses avantages" ID="ID_1176989344" CREATED="1314878156227" MODIFIED="1314878220300"/>
<node TEXT="sous fenetre sdl avec ses avantages aussi" ID="ID_113936964" CREATED="1314878162725" MODIFIED="1314878268184"/>
<node TEXT="WinMain" ID="ID_88026294" CREATED="1314878171827" MODIFIED="1314878179772">
<node TEXT="on parse les msg wnd" ID="ID_1517644861" CREATED="1314878180018" MODIFIED="1314878191696"/>
<node TEXT="puis les SDL" ID="ID_890593131" CREATED="1314878191940" MODIFIED="1314878194419"/>
</node>
<node TEXT="mono thread" ID="ID_1132577200" CREATED="1314878195596" MODIFIED="1314878199485"/>
<node TEXT="D&#xe9;coupage des fichiers (des .c et .h hein)" ID="ID_1371212341" CREATED="1314878337215" MODIFIED="1314969803131">
<node TEXT="???" ID="ID_674762767" CREATED="1314878368135" MODIFIED="1314878369281"/>
<node TEXT="Serait bien propre d&apos;isoler SDL de la partie Windows mais rend difficile les probl&#xe9;matiques de communication" ID="ID_1070041831" CREATED="1314878369575" MODIFIED="1314878431754"/>
<node TEXT="&#xe7;a doit se faire par l&apos;interfa&#xe7;age des classes... On partage ensuite un pointeur global !" ID="ID_79042899" CREATED="1314882819893" MODIFIED="1314882855657"/>
<node TEXT="Faut aussi pr&#xe9;voir pour la musique !!!" ID="ID_1434530444" CREATED="1314883475485" MODIFIED="1314883482379"/>
</node>
</node>
</node>
<node TEXT="A la vue du d&#xe9;but du d&#xe9;veloppement d&apos;un proto" POSITION="right" ID="ID_1373470663" CREATED="1314969835496" MODIFIED="1314969866436">
<node TEXT="Il faut faire une classe de gestion des sprites (que tu as bien attaqu&#xe9;, Alex)" ID="ID_1476051684" CREATED="1314969866822" MODIFIED="1314969881669">
<node TEXT="J&apos;ai d&#xe9;j&#xe0; ajout&#xe9; un truc : il faut qu&apos;on puisse conna&#xee;tre le nombre de sprite par action (par exemple, pour v&#xe9;rifier qu&apos;on est pas en train d&apos;appeler des sprites qui n&apos;existent pas)" ID="ID_1076547524" CREATED="1314970627955" MODIFIED="1314970678290"/>
<node TEXT="peut-&#xea;tre aussi le nombre de sens par action" ID="ID_1943918887" CREATED="1314970647775" MODIFIED="1314970656170"/>
<node TEXT="&#xe0; discuter !!!" ID="ID_890445073" CREATED="1314970680408" MODIFIED="1314970683109"/>
</node>
<node TEXT="Il faut faire une classe de gestion des sons et des musiques" ID="ID_805576364" CREATED="1314969888748" MODIFIED="1314969898504"/>
<node TEXT="Serait-il int&#xe9;ressant de faire quelque chose qui dispense de la r&#xe9;solution choisie ?" ID="ID_427779374" CREATED="1314973034494" MODIFIED="1314973107667">
<node TEXT="par exemple : on aurait une surface de dessin qui serait 1024x768, puis la surface qui est affich&#xe9;e dans la fen&#xea;tre est la taille que l&apos;utilisateur choisi, et boom, on adapte la surface de dessin &#xe0; cette surface d&apos;afihcage" ID="ID_60964618" CREATED="1314973108435" MODIFIED="1314973169563"/>
</node>
</node>
</node>
</map>
