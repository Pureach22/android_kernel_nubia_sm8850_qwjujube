__int64 __fastcall lim_gen_link_specific_assoc_rsp(__int64 a1, __int64 a2, int a3, unsigned int a4)
{
  unsigned __int64 v4; // x24
  __int64 v9; // x27
  __int64 v10; // x28
  int v11; // w23
  unsigned __int8 *v12; // x21
  double updated; // d0
  __int64 v14; // x3
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w25
  unsigned int v23; // w26
  unsigned int v24; // w0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int v33; // w20
  __int64 result; // x0
  __int64 v36; // [xsp+10h] [xbp-20h] BYREF
  int v37[2]; // [xsp+18h] [xbp-18h]
  unsigned int v38; // [xsp+20h] [xbp-10h] BYREF
  unsigned __int16 v39; // [xsp+24h] [xbp-Ch]
  __int64 v40; // [xsp+28h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v36 = 0;
  v39 = 0;
  v38 = 0;
  *(_QWORD *)v37 = _qdf_mem_malloc(a4, "lim_gen_link_specific_assoc_rsp", 2866);
  if ( *(_QWORD *)v37 )
  {
    qdf_mem_copy(&v38, (const void *)(a2 + 30), 6u);
    v9 = *(unsigned __int8 *)(a2 + 10696);
    LODWORD(v36) = a4;
    if ( v9 )
    {
      v10 = 0;
      v11 = a4 - 24;
      v12 = (unsigned __int8 *)(a2 + 10710);
      do
      {
        if ( v10 == 3 )
          __break(0x5512u);
        v22 = v12[6];
        if ( v22 != 255 && v22 == *(unsigned __int8 *)(a2 + 10) )
        {
          v23 = *v12;
          v4 = v4 & 0xFFFF000000000000LL | v38 | ((unsigned __int64)v39 << 32);
          v24 = util_gen_link_assoc_rsp(a3 + 24, v11, 1, v23, v4, v37[0], a4, (__int64)&v36);
          if ( v24 )
          {
            v33 = v24;
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: MLO ROAM: link_id:%d vdev:%d Reassoc generation failed %d",
              v25,
              v26,
              v27,
              v28,
              v29,
              v30,
              v31,
              v32,
              "lim_gen_link_specific_assoc_rsp",
              v23,
              v22);
            mlo_free_cache_link_assoc_rsp(*(_QWORD *)(a2 + 16), v23);
            goto LABEL_12;
          }
          updated = mlo_update_cache_link_assoc_rsp(*(_QWORD *)(a2 + 16), v23, &v36);
          mgmt_txrx_frame_hex_dump(*(__int64 *)v37, v36, 0, v14, updated, v15, v16, v17, v18, v19, v20, v21);
          lim_process_assoc_rsp_frame(a1, *(_QWORD *)v37, (unsigned int)v36, 1, a2);
        }
        ++v10;
        v12 += 48;
      }
      while ( v9 != v10 );
    }
    v33 = 0;
LABEL_12:
    _qdf_mem_free(*(__int64 *)v37);
    result = v33;
  }
  else
  {
    result = 2;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
