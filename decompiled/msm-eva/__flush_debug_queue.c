__int64 __fastcall _flush_debug_queue(_QWORD *a1, unsigned int *a2)
{
  int v4; // w27
  unsigned int *v5; // x21
  __int64 result; // x0
  unsigned __int64 v7; // x28
  __int64 v8; // x23
  __int64 v9; // x3
  __int64 v10; // x8
  unsigned int (__fastcall *v11)(_QWORD); // x8
  __int64 v12; // x8
  unsigned __int64 v13; // x9
  unsigned __int64 v14; // x8
  unsigned __int64 StatusReg; // x8
  int v16; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    v4 = 4096;
    v5 = a2;
  }
  else
  {
    result = _kmalloc_large_noprof(12288, 3520);
    v5 = (unsigned int *)result;
    if ( !result )
    {
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        result = printk(
                   &unk_88A4A,
                   *(unsigned int *)(StatusReg + 1800),
                   *(unsigned int *)(StatusReg + 1804),
                   &unk_8E7CE);
      }
      goto LABEL_45;
    }
    v4 = 1;
  }
  v7 = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v8 = a1[276];
    v16 = 0;
    result = mutex_is_locked(a1 + 10);
    if ( (result & 1) == 0 && *(_BYTE *)(v8 + 376) )
    {
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        result = printk(&unk_8E7D2, *(unsigned int *)(v7 + 1800), *(unsigned int *)(v7 + 1804), &unk_8E7CE);
      __break(0x800u);
    }
    if ( !a1[178] )
      break;
    result = _read_queue(a1 + 175, v5, &v16);
    if ( (_DWORD)result )
      goto LABEL_43;
    if ( v16 )
    {
      v10 = a1[314];
      if ( v10 )
      {
        v11 = *(unsigned int (__fastcall **)(_QWORD))(v10 + 56);
        if ( v11 )
        {
          if ( *((_DWORD *)v11 - 1) != -1303076162 )
            __break(0x8228u);
          if ( v11(a1) && (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
            printk(&unk_920E3, *(unsigned int *)(v7 + 1800), *(unsigned int *)(v7 + 1804), &unk_8E7CE);
        }
      }
      _write_register((__int64)a1, 0xA0150u, 1u);
    }
    v12 = *v5;
    if ( (unsigned int)v12 > 7 )
    {
      if ( v5[1] == 34607109 )
      {
        if ( (unsigned int)v12 < 0x18 || (v13 = v5[3], (unsigned int)v13 < 3) || v12 - 23 < v13 )
        {
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
            printk(&unk_8A633, *(unsigned int *)(v7 + 1800), *(unsigned int *)(v7 + 1804), &unk_8E7CE);
        }
        else
        {
          *((_BYTE *)v5 + (unsigned int)(v13 - 1) + 24) = 0;
          if ( (msm_cvp_debug & v4) != 0 && !msm_cvp_debug_out )
          {
            if ( a2 )
              printk(&unk_8F362, "fw", (char *)v5 + 25, v9);
            else
              printk(&unk_94CDC, *(unsigned int *)(v7 + 1800), *(unsigned int *)(v7 + 1804), &unk_8E7CE);
          }
        }
      }
    }
    else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      printk(&unk_92E81, *(unsigned int *)(v7 + 1800), *(unsigned int *)(v7 + 1804), &unk_8E7CE);
    }
  }
  if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
  {
LABEL_43:
    if ( a2 )
      goto LABEL_45;
    goto LABEL_44;
  }
  v14 = _ReadStatusReg(SP_EL0);
  result = printk(&unk_94204, *(unsigned int *)(v14 + 1800), *(unsigned int *)(v14 + 1804), &unk_8E7CE);
  if ( !a2 )
LABEL_44:
    result = kfree(v5);
LABEL_45:
  _ReadStatusReg(SP_EL0);
  return result;
}
