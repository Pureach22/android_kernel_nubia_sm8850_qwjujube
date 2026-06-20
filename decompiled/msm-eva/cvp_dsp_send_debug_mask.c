__int64 cvp_dsp_send_debug_mask()
{
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  int v2; // [xsp+0h] [xbp-90h] BYREF
  __int64 v3; // [xsp+4h] [xbp-8Ch]
  __int64 v4; // [xsp+Ch] [xbp-84h]
  __int64 v5; // [xsp+14h] [xbp-7Ch]
  __int64 v6; // [xsp+1Ch] [xbp-74h]
  __int64 v7; // [xsp+24h] [xbp-6Ch]
  __int64 v8; // [xsp+2Ch] [xbp-64h]
  __int64 v9; // [xsp+34h] [xbp-5Ch]
  __int64 v10; // [xsp+3Ch] [xbp-54h]
  __int64 v11; // [xsp+44h] [xbp-4Ch]
  __int64 v12; // [xsp+4Ch] [xbp-44h]
  __int64 v13; // [xsp+54h] [xbp-3Ch]
  __int64 v14; // [xsp+5Ch] [xbp-34h]
  __int64 v15; // [xsp+64h] [xbp-2Ch]
  _BYTE v16[28]; // [xsp+6Ch] [xbp-24h] BYREF
  __int64 v17; // [xsp+88h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = 0;
  v14 = 0;
  v13 = 0;
  v12 = 0;
  v11 = 0;
  v10 = 0;
  v8 = 0;
  v7 = 0;
  v6 = 0;
  v5 = 0;
  v4 = 0;
  v3 = 0;
  v2 = 7;
  v9 = (unsigned int)dword_6C66C;
  if ( (msm_cvp_debug & 0x800) != 0 && !msm_cvp_debug_out )
    printk(&unk_8907A, "dsp", "cvp_dsp_send_debug_mask", (unsigned int)dword_6C66C);
  result = cvp_dsp_send_cmd_sync(&v2, (__int64)v16);
  if ( (_DWORD)result && (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    result = printk(&unk_94846, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
