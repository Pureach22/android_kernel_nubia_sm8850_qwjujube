__int64 ipclite_hw_mutex_release()
{
  __int64 v0; // x8
  _DWORD *v1; // x9

  v0 = ipclite;
  if ( ipclite )
  {
    v1 = *(_DWORD **)(ipclite + 6352);
    if ( *v1 )
    {
      return 4294967274LL;
    }
    else
    {
      *v1 = 255;
      _hwspin_unlock(*(_QWORD *)(v0 + 6456), 1, v0 + 6464);
      return 0;
    }
  }
  else
  {
    printk(&unk_F98D, "ipclite", "ipclite_hw_mutex_release");
    return 4294967284LL;
  }
}
