__int64 __fastcall curr_list_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x21
  int v6; // w3
  __int64 v7; // x19

  v3 = *(_QWORD *)(a1 + 152);
  mutex_lock(v3 + 24);
  v6 = *(unsigned __int8 *)(v3 + 332);
  if ( v6 == 255 )
  {
    dev_err(a1, "curr_list is not set.\n");
    v7 = -22;
  }
  else
  {
    v7 = (int)scnprintf(a3, 4096, "%d\n", v6);
  }
  mutex_unlock(v3 + 24);
  return v7;
}
