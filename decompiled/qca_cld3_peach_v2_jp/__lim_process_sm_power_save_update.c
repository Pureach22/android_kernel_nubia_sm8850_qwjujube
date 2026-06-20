__int64 __fastcall _lim_process_sm_power_save_update(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v13; // x23
  unsigned __int8 *v14; // x25
  unsigned int v15; // w22
  __int64 v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x21
  unsigned int v26; // w0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  int v43; // w8
  __int64 v44; // x1
  __int64 v45; // x4
  __int64 v46; // x5
  __int64 v47; // x6
  __int64 v48; // x7
  __int64 result; // x0
  const char *v50; // x2
  unsigned int v51; // w1
  _WORD v52[2]; // [xsp+0h] [xbp-10h] BYREF
  __int16 v53; // [xsp+4h] [xbp-Ch] BYREF
  unsigned __int8 v54; // [xsp+6h] [xbp-Ah]
  __int64 v55; // [xsp+8h] [xbp-8h]

  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = *(unsigned __int8 **)(a2 + 16);
  v13 = *(_QWORD *)(a2 + 24);
  v15 = *(_DWORD *)(a2 + 40);
  v54 = 0;
  v53 = 0;
  v52[0] = 0;
  v16 = dph_lookup_hash_entry(a4, a5, a6, a7, a8, a9, a10, a11, a1, v14 + 10, v52, a3 + 360);
  if ( v16 )
  {
    v25 = v16;
    v26 = dot11f_unpack_sm_power_save(a1, v13, v15, &v53, 0);
    if ( (v26 & 0x10000000) != 0 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to unpack and parse a Update SM Power (0x%08x, %d bytes):",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "__lim_process_sm_power_save_update",
        v26,
        v15);
      result = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD))qdf_trace_hex_dump)(53, 2, v13, v15);
    }
    else
    {
      if ( v26 )
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: There were warnings while unpacking a SMPower Save update (0x%08x, %d bytes):",
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          "__lim_process_sm_power_save_update",
          v26,
          v15);
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Received SM Power save Mode update Frame with PS_Enable: %dPS Mode: %d",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "__lim_process_sm_power_save_update",
        v54 & 1,
        (v54 >> 1) & 1);
      v43 = v54 & 3;
      if ( (v54 & 3) != 0 )
      {
        if ( v43 == 1 )
        {
          v44 = 0;
        }
        else
        {
          if ( v43 != 3 )
          {
            v50 = "%s: Received SM Power save Mode update Frame with invalid mode";
            v51 = 3;
            goto LABEL_20;
          }
          v44 = 1;
        }
      }
      else
      {
        v44 = 3;
      }
      if ( (_DWORD)v44 == *(_DWORD *)(v25 + 328) )
      {
        v50 = "%s: The PEER is already set in the same mode";
        v51 = 2;
LABEL_20:
        result = qdf_trace_msg(
                   0x35u,
                   v51,
                   v50,
                   v35,
                   v36,
                   v37,
                   v38,
                   v39,
                   v40,
                   v41,
                   v42,
                   "__lim_process_sm_power_save_update");
        goto LABEL_21;
      }
      *(_DWORD *)(v25 + 328) = v44;
      result = lim_post_sm_state_update(a1, v44, v25 + 338, *(unsigned __int8 *)(a3 + 10));
    }
  }
  else
  {
    if ( v14 == (unsigned __int8 *)-10LL )
    {
      v47 = 0;
      v45 = 0;
      v46 = 0;
      v48 = 0;
    }
    else
    {
      v45 = v14[10];
      v46 = v14[11];
      v47 = v14[12];
      v48 = v14[15];
    }
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: STA context not found - ignoring UpdateSM PSave Mode from SA: %02x:%02x:%02x:**:**:%02x",
               v17,
               v18,
               v19,
               v20,
               v21,
               v22,
               v23,
               v24,
               "__lim_process_sm_power_save_update",
               v45,
               v46,
               v47,
               v48);
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
