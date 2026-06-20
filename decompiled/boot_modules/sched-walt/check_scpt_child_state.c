__int64 __fastcall check_scpt_child_state(__int64 result)
{
  unsigned __int64 StatusReg; // x8
  _DWORD *v2; // x9

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = &vendor_data_pad;
  if ( (_UNKNOWN *)StatusReg != &init_task )
    v2 = (_DWORD *)(StatusReg + 5184);
  if ( result
    && *((_BYTE *)v2 + 456) == 1
    && v2[120] == 1
    && (unsigned int)(*(_DWORD *)(result + 1352) - 3) >= 0xFFFFFFFE
    && (unsigned int)(*(_DWORD *)(StatusReg + 1352) - 3) >= 0xFFFFFFFE )
  {
    result = q_restore_cfs_task(*(_DWORD *)(result + 1800), v2[121]);
    if ( byte_6A5A8 == 1 )
      return printk(&unk_65F57);
  }
  return result;
}
