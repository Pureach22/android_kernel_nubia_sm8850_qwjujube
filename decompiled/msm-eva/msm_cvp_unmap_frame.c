__int64 __fastcall msm_cvp_unmap_frame(__int64 result, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x21
  __int64 v4; // x0
  _QWORD *v5; // x8
  __int64 v6; // x9
  _QWORD *v7; // x20
  _QWORD *v8; // x9
  __int64 v9; // x8
  __int64 v10; // x23
  __int64 v11; // x26
  _BYTE *v12; // x1
  int v13; // w8
  unsigned __int64 StatusReg; // x8

  if ( result )
  {
    v2 = result;
    v3 = a2 & 0x7FFFFFFFFFFFFFFFLL;
    if ( (msm_cvp_debug & 0x40) != 0 && !msm_cvp_debug_out )
      printk(
        &unk_95B22,
        &unk_84256,
        "msm_cvp_unmap_frame",
        (unsigned int)(*(_DWORD *)(result + 324) ^ *(_DWORD *)(result + 320)));
    v4 = mutex_lock(v2 + 680);
    v5 = *(_QWORD **)(v2 + 664);
    do
    {
      if ( v5 == (_QWORD *)(v2 + 664) )
      {
        result = mutex_unlock(v2 + 680);
        if ( (msm_cvp_debug & 8) != 0 && !msm_cvp_debug_out )
          return printk(&unk_8598E, "cmd", "msm_cvp_unmap_frame", v3);
        return result;
      }
      v6 = v5[323];
      v7 = v5;
      v5 = (_QWORD *)*v5;
    }
    while ( v6 != v3 );
    v8 = (_QWORD *)v7[1];
    if ( (_QWORD *)*v8 == v7 && (_QWORD *)v5[1] == v7 )
    {
      v5[1] = v8;
      *v8 = v5;
    }
    else
    {
      v4 = _list_del_entry_valid_or_report(v7);
    }
    *v7 = 0xDEAD000000000100LL;
    v7[1] = 0xDEAD000000000122LL;
    if ( (msm_cvp_debug & 8) == 0 || msm_cvp_debug_out )
    {
      v9 = *((unsigned int *)v7 + 644);
      if ( (_DWORD)v9 )
        goto LABEL_14;
      goto LABEL_27;
    }
    v4 = printk(&unk_85002, "cmd", "msm_cvp_unmap_frame", *((unsigned int *)v7 + 648));
    v9 = *((unsigned int *)v7 + 644);
    if ( !(_DWORD)v9 )
      goto LABEL_27;
LABEL_14:
    if ( (int)v9 > 40 )
    {
LABEL_27:
      msm_cvp_unmap_frame_buf(v2);
      return mutex_unlock(v2 + 680);
    }
    *(_QWORD *)(v2 + 728) = v7[323];
    *(_DWORD *)(v2 + 736) = *((_DWORD *)v7 + 644);
    if ( (unsigned int)(v9 - 1) <= 0x27 )
    {
      v10 = (v9 << 32) - 0x100000000LL;
      v11 = v9 - 1;
      while ( 1 )
      {
        v12 = *(_BYTE **)((char *)v7 + (v10 >> 26) + 72);
        if ( (v12[84] & 1) != 0 )
          break;
        memcpy((void *)(v2 + 744 + 152LL * SHIDWORD(v10)), v12, 0x98u);
        v13 = v11--;
        v10 -= 0x100000000LL;
        if ( !v13 )
          goto LABEL_27;
      }
      *(_DWORD *)(v2 + 736) = 0;
      goto LABEL_27;
    }
    __break(0x5512u);
    return msm_cvp_unmap_frame_buf(v4);
  }
  else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    return printk(&unk_912BD, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
  }
  return result;
}
