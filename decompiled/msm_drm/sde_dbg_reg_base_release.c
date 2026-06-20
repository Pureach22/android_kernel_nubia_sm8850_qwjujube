__int64 __fastcall sde_dbg_reg_base_release(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x0
  _QWORD *v4; // x19
  __int64 v5; // t1

  if ( !a2 )
    return 4294967274LL;
  v2 = *(_QWORD *)(a2 + 32);
  if ( !v2 )
    return 4294967277LL;
  mutex_lock(&unk_2942D0);
  v5 = *(_QWORD *)(v2 + 152);
  v4 = (_QWORD *)(v2 + 152);
  v3 = v5;
  if ( v5 )
  {
    kfree(v3);
    *v4 = 0;
    v4[1] = 0;
  }
  mutex_unlock(&unk_2942D0);
  return 0;
}
