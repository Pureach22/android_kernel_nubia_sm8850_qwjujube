__int64 __fastcall cscfg_update_feat_param_val(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 v6; // x9
  unsigned int v7; // w19
  _QWORD *i; // x10
  _QWORD *v9; // x12

  mutex_lock(&cscfg_mutex);
  v6 = cscfg_mgr;
  if ( *(_DWORD *)(cscfg_mgr + 976) )
  {
    v7 = -16;
  }
  else if ( (a2 & 0x80000000) != 0 || *(_DWORD *)(a1 + 36) <= (signed int)a2 )
  {
    v7 = -22;
  }
  else
  {
    *(_QWORD *)(*(_QWORD *)(a1 + 40) + 16LL * a2 + 8) = a3;
    for ( i = *(_QWORD **)(v6 + 912); i != (_QWORD *)(v6 + 912); i = (_QWORD *)*i )
    {
      v9 = (_QWORD *)(*(i - 3) + 1008LL);
      while ( 1 )
      {
        v9 = (_QWORD *)*v9;
        if ( v9 == (_QWORD *)(*(i - 3) + 1008LL) )
          break;
        if ( *(v9 - 2) == a1 )
        {
          if ( v9 != &qword_10 )
          {
            *(_QWORD *)(v9[4] + 32LL * a2 + 16) = a3;
            v6 = cscfg_mgr;
          }
          break;
        }
      }
    }
    v7 = 0;
  }
  mutex_unlock(&cscfg_mutex);
  return v7;
}
