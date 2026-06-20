void __fastcall qlpmm_disconnect_del_client_cb(__int64 a1, int a2, int a3)
{
  _DWORD *v3; // x8
  __int64 *v4; // x9
  __int64 v5; // x10

  v3 = (_DWORD *)qlpmm_pd;
  v4 = *(__int64 **)(qlpmm_pd + 400);
  v5 = qlpmm_pd + 400;
  while ( v4 != (__int64 *)v5 )
  {
    if ( *((_BYTE *)v4 + 28) == 1 && *((_DWORD *)v4 + 5) == a2 && *((_DWORD *)v4 + 6) == a3 )
    {
      *((_BYTE *)v4 + 28) = 0;
      --*v3;
    }
    v4 = (__int64 *)*v4;
  }
}
