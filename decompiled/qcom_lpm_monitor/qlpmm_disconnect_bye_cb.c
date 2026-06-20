void __fastcall qlpmm_disconnect_bye_cb(__int64 a1, int a2)
{
  _DWORD *v2; // x8
  __int64 *v3; // x9
  __int64 v4; // x10

  v2 = (_DWORD *)qlpmm_pd;
  v3 = *(__int64 **)(qlpmm_pd + 400);
  v4 = qlpmm_pd + 400;
  while ( v3 != (__int64 *)v4 )
  {
    if ( *((_BYTE *)v3 + 28) == 1 && *((_DWORD *)v3 + 5) == a2 )
    {
      *((_BYTE *)v3 + 28) = 0;
      --*v2;
    }
    v3 = (__int64 *)*v3;
  }
}
