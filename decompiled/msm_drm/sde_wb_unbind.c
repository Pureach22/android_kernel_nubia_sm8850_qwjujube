__int64 __fastcall sde_wb_unbind(__int64 a1)
{
  _QWORD *v1; // x19

  if ( !a1 )
    return printk(&unk_223EAA, "sde_wb_unbind");
  v1 = *(_QWORD **)(a1 + 152);
  if ( !v1 )
    return printk(&unk_27130C, "sde_wb_unbind");
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "\n");
  mutex_lock(v1 + 6);
  *v1 = 0;
  return mutex_unlock(v1 + 6);
}
