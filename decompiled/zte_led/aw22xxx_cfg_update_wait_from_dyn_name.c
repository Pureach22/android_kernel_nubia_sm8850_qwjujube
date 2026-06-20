__int64 __fastcall aw22xxx_cfg_update_wait_from_dyn_name(__int64 a1)
{
  char v2; // w9
  char v3; // w9
  __int64 result; // x0
  void *v5; // x0
  _QWORD v6[2]; // [xsp+0h] [xbp-10h] BYREF

  v6[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6[0] = 0;
  printk(&unk_130E1, "aw22xxx_cfg_update_wait_from_dyn_name");
  if ( *(_BYTE *)(a1 + 751) != 2 )
  {
    v5 = &unk_12EC6;
LABEL_12:
    result = printk(v5, "aw22xxx_cfg_update_wait_from_dyn_name");
    goto LABEL_9;
  }
  if ( *(_DWORD *)(a1 + 768) != 2 )
  {
    v3 = g_init_flg;
    *(_BYTE *)(a1 + 840) = 1;
    if ( (v3 & 1) != 0 )
      goto LABEL_7;
    goto LABEL_6;
  }
  v2 = g_init_flg;
  *(_BYTE *)(a1 + 840) = 0;
  if ( (v2 & 1) == 0 )
  {
LABEL_6:
    g_init_flg = 1;
    aw22xxx_init_cfg_update_array(a1);
  }
LABEL_7:
  if ( (unsigned int)request_firmware(v6, aw22xxx_dyn_name, *(_QWORD *)(a1 + 8)) )
  {
    v5 = &unk_13AEA;
    goto LABEL_12;
  }
  ((void (__fastcall *)(_QWORD, __int64))aw22xxx_cfg_loaded)(v6[0], a1);
  result = msleep(20);
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
