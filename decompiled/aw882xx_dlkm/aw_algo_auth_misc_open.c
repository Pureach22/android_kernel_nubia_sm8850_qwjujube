__int64 __fastcall aw_algo_auth_misc_open(__int64 a1, __int64 a2, __int64 a3)
{
  _QWORD *v3; // x9
  _UNKNOWN ***v4; // x10
  __int64 result; // x0

  v3 = g_dev_list;
  if ( g_dev_list == (_UNKNOWN *)&g_dev_list )
  {
    printk(&unk_288F5, "aw_algo_auth_misc_open", a3);
    *(_QWORD *)(a2 + 32) = 0;
    return 4294967274LL;
  }
  else
  {
    do
    {
      v4 = (_UNKNOWN ***)v3;
      if ( !*((_DWORD *)v3 - 293) )
        break;
      v3 = (_QWORD *)*v3;
    }
    while ( *v4 != &g_dev_list );
    if ( v4 == &qword_4C8 )
    {
      printk(&unk_28D7A, "aw_algo_auth_misc_open", 0);
      return 4294967274LL;
    }
    else
    {
      result = 0;
      *(_QWORD *)(a2 + 32) = v4 - 153;
    }
  }
  return result;
}
