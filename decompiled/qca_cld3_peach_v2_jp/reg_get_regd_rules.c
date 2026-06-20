__int64 __fastcall reg_get_regd_rules(
        __int64 a1,
        void *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 pdev_obj; // x0
  __int64 v12; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v14; // x9
  const char *v16; // x2

  if ( !a1 )
  {
    v16 = "%s: pdev is NULL";
LABEL_12:
    qdf_trace_msg(0x51u, 2u, v16, a3, a4, a5, a6, a7, a8, a9, a10, "reg_get_regd_rules");
    return 16;
  }
  pdev_obj = reg_get_pdev_obj(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !pdev_obj )
  {
    v16 = "%s: pdev priv obj is NULL";
    goto LABEL_12;
  }
  v12 = pdev_obj;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(pdev_obj + 58184);
  }
  else
  {
    raw_spin_lock_bh(pdev_obj + 58184);
    *(_QWORD *)(v12 + 58192) |= 1uLL;
  }
  qdf_mem_copy(a2, (const void *)(v12 + 57460), 0x2D0u);
  v14 = *(_QWORD *)(v12 + 58192);
  if ( (v14 & 1) != 0 )
  {
    *(_QWORD *)(v12 + 58192) = v14 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v12 + 58184);
  }
  else
  {
    raw_spin_unlock(v12 + 58184);
  }
  return 0;
}
