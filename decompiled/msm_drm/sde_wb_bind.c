__int64 __fastcall sde_wb_bind(__int64 a1, __int64 a2)
{
  _QWORD *v3; // x20
  void *v5; // x0

  if ( !a1 || !a2 )
  {
    v5 = &unk_223EAA;
LABEL_10:
    printk(v5, "sde_wb_bind");
    return 4294967274LL;
  }
  v3 = *(_QWORD **)(a1 + 152);
  if ( !v3 )
  {
    v5 = &unk_27130C;
    goto LABEL_10;
  }
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "\n");
  mutex_lock(v3 + 6);
  *v3 = *(_QWORD *)(a2 + 152);
  mutex_unlock(v3 + 6);
  return 0;
}
