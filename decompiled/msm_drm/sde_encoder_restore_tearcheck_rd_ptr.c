__int64 __fastcall sde_encoder_restore_tearcheck_rd_ptr(__int64 *a1)
{
  unsigned int disp_op; // w0
  __int64 v5; // x23
  unsigned int v6; // w21
  __int64 v7; // x20
  int v8; // w0
  int v9; // w22
  __int64 (__fastcall *v10)(__int64, char *, __int64 *); // x8
  unsigned int v11; // w27
  int v12; // w25
  __int64 v13; // x28
  __int64 v14; // x0
  int v15; // w6
  int v16; // w4
  __int64 result; // x0
  __int64 v18; // x23
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x26
  __int64 v22; // x24
  __int64 v23; // x22
  __int64 v24; // x0
  int v25; // w10
  int v26; // w25
  unsigned int v27; // w22
  _DWORD *v28; // x8
  __int64 v29; // x24
  int v30; // w20
  int v31; // w21
  int v32; // w0
  int v33; // w4
  __int64 v39; // [xsp+38h] [xbp-98h]
  char v40[2]; // [xsp+44h] [xbp-8Ch] BYREF
  __int64 v41; // [xsp+48h] [xbp-88h] BYREF
  _QWORD v42[2]; // [xsp+50h] [xbp-80h] BYREF
  __int64 v43; // [xsp+60h] [xbp-70h]
  __int64 v44; // [xsp+68h] [xbp-68h]
  __int64 v45; // [xsp+70h] [xbp-60h]
  __int64 v46; // [xsp+78h] [xbp-58h]
  __int64 v47; // [xsp+80h] [xbp-50h]
  __int64 v48; // [xsp+88h] [xbp-48h]
  __int64 v49; // [xsp+90h] [xbp-40h]
  __int64 v50; // [xsp+98h] [xbp-38h]
  __int64 v51; // [xsp+A0h] [xbp-30h]
  __int64 v52; // [xsp+A8h] [xbp-28h]
  __int64 v53; // [xsp+B0h] [xbp-20h]
  __int64 v54; // [xsp+B8h] [xbp-18h]
  __int64 v55; // [xsp+C0h] [xbp-10h]

  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v53 = 0;
  v54 = 0;
  v51 = 0;
  v52 = 0;
  v49 = 0;
  v50 = 0;
  v47 = 0;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  v42[0] = 0;
  v42[1] = 0;
  v41 = 0;
  *(_WORD *)v40 = 0;
  if ( !a1 || !a1[1] )
  {
    result = printk(&unk_26FEB0, "sde_encoder_restore_tearcheck_rd_ptr");
LABEL_44:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  disp_op = sde_encoder_get_disp_op(*a1);
  v5 = a1[1];
  v6 = disp_op;
  v7 = a1[53];
  v39 = *a1;
  v8 = drm_mode_vrefresh(a1 + 65);
  v9 = *((unsigned __int16 *)a1 + 270);
  v10 = *(__int64 (__fastcall **)(__int64, char *, __int64 *))(v5 + 3232);
  v11 = v9 + *((_DWORD *)a1 + 726) + 1;
  if ( v9 == 1 )
    v12 = 0;
  else
    v12 = 1000000000 / v8;
  if ( v9 == 1 )
    v13 = 1000000000 / v8;
  else
    v13 = 0;
  if ( !v10 )
    goto LABEL_20;
  v14 = *(_QWORD *)(v5 + 2760);
  if ( *((_DWORD *)v10 - 1) != 704716645 )
    __break(0x8228u);
  v15 = v10(v14, v40, &v41);
  if ( v15 || v11 <= *(unsigned __int16 *)v40 )
  {
    if ( (_drm_debug & 4) != 0 )
    {
      if ( *a1 )
        v16 = *(_DWORD *)(*a1 + 24);
      else
        v16 = -1;
      _drm_dev_dbg(0, 0, 0, "enc%d intf%d failed to get panel scan line, rc=%d\n", v16, *((_DWORD *)a1 + 168) - 1, v15);
    }
LABEL_20:
    *(_WORD *)v40 = v11;
  }
  v18 = raw_spin_lock_irqsave(a1[103]);
  v19 = ((__int64 (__fastcall *)(__int64, _QWORD *))sde_encoder_helper_get_pp_line_count)(*a1, v42);
  v20 = ktime_get(v19);
  v21 = a1[108];
  v22 = v20;
  if ( v41 )
  {
    v23 = v13 + v12 / v9;
    v24 = ktime_get(v20);
    if ( (unsigned __int64)(v23 + 1) >= 3 )
      v25 = 0;
    else
      v25 = v23;
    v26 = (v24 - v41 - (v24 - v41) * 1 / v23 * v23) / v23 + (v24 - v41) * v25;
  }
  else
  {
    v26 = 0;
  }
  if ( v26 + (unsigned int)*(unsigned __int16 *)v40 >= v11 )
    v27 = v11;
  else
    v27 = v26 + *(unsigned __int16 *)v40;
  if ( !v7 )
  {
LABEL_36:
    v29 = v22 - v21;
    raw_spin_unlock_irqrestore(a1[103], v18);
    v30 = sde_dbg_base_evtlog;
    if ( *a1 )
      v31 = *(_DWORD *)(*a1 + 24);
    else
      v31 = -1;
    v32 = drm_mode_vrefresh(a1 + 65);
    result = sde_evtlog_log(
               v30,
               "sde_encoder_restore_tearcheck_rd_ptr",
               294,
               -1,
               v31,
               v32,
               *(_DWORD *)(v39 + 4808),
               *((unsigned __int16 *)a1 + 270),
               v40[0]);
    if ( (_drm_debug & 4) != 0 )
    {
      if ( *a1 )
        v33 = *(_DWORD *)(*a1 + 24);
      else
        v33 = -1;
      result = _drm_dev_dbg(
                 0,
                 0,
                 0,
                 "enc%d intf%d scan_line:%u rest_rd_ptr:%u rd_ptr:%u frame_ns:%llu\n",
                 v33,
                 *((_DWORD *)a1 + 168) - 1,
                 *(unsigned __int16 *)v40,
                 v27,
                 (unsigned int)v43 - *((unsigned __int16 *)a1 + 267),
                 v29 / 1000);
    }
    goto LABEL_44;
  }
  if ( v6 < 3 )
  {
    v28 = *(_DWORD **)(v7 + 8LL * v6 + 1208);
    if ( v28 )
    {
      if ( *(v28 - 1) != -1913620264 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD))v28)(v7, v27);
    }
    goto LABEL_36;
  }
  __break(0x5512u);
  __asm { FMLS            H2, H14, V8.H[5] }
  return sde_encoder_phys_cmd_dynamic_irq_control();
}
