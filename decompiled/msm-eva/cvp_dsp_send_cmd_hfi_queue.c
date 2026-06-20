__int64 __fastcall cvp_dsp_send_cmd_hfi_queue(__int64 a1, unsigned int a2, __int64 a3)
{
  int ddrtype; // w0
  __int16 v6; // w9
  int v7; // w8
  __int64 result; // x0
  unsigned __int64 v9; // x8
  unsigned int v10; // w19
  unsigned __int64 StatusReg; // x8
  _QWORD v12[3]; // [xsp+8h] [xbp-78h] BYREF
  int v13; // [xsp+20h] [xbp-60h]
  int v14; // [xsp+24h] [xbp-5Ch]
  int v15; // [xsp+28h] [xbp-58h]
  int v16; // [xsp+2Ch] [xbp-54h]
  __int64 v17; // [xsp+30h] [xbp-50h]
  __int64 v18; // [xsp+38h] [xbp-48h]
  __int64 v19; // [xsp+40h] [xbp-40h]
  __int64 v20; // [xsp+48h] [xbp-38h]
  __int64 v21; // [xsp+50h] [xbp-30h]
  __int64 v22; // [xsp+58h] [xbp-28h]
  __int64 v23; // [xsp+60h] [xbp-20h]
  __int64 v24; // [xsp+68h] [xbp-18h]
  int v25; // [xsp+70h] [xbp-10h]
  __int64 v26; // [xsp+78h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = 0;
  v25 = 0;
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  v17 = 0;
  v18 = 0;
  v15 = 0;
  v12[0] = 0;
  v12[1] = a1;
  v12[2] = a2;
  v13 = 1;
  ddrtype = cvp_of_fdt_get_ddrtype();
  v6 = msm_cvp_debug;
  v7 = msm_cvp_debug_out;
  v16 = ddrtype;
  if ( (ddrtype & 0x80000000) == 0 )
  {
    if ( (msm_cvp_debug & 0x800) == 0 )
      goto LABEL_10;
    goto LABEL_8;
  }
  if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    printk(&unk_934F2, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
    v6 = msm_cvp_debug;
    v7 = msm_cvp_debug_out;
  }
  v16 = 9;
  if ( (v6 & 0x800) != 0 )
  {
LABEL_8:
    if ( !v7 )
      printk(&unk_91BB0, "dsp", "cvp_dsp_send_cmd_hfi_queue", a1);
  }
LABEL_10:
  result = cvp_dsp_send_cmd_sync(v12, a3);
  if ( (_DWORD)result && (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v9 = _ReadStatusReg(SP_EL0);
    v10 = result;
    printk(&unk_94846, *(unsigned int *)(v9 + 1800), *(unsigned int *)(v9 + 1804), &unk_8E7CE);
    result = v10;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
