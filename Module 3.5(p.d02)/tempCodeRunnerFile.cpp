void dfs(int s){
    cout<<s<<endl;
      visi[s]=true;
    for(int child: adj[s])
    if(visi[child]==false){
        dfs(child);
    }
}
