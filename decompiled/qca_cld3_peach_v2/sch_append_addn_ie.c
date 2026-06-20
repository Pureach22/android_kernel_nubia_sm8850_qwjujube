__int64 __fastcall sch_append_addn_ie(
        __int64 a1,
        __int64 a2,
        void *a3,
        unsigned int a4,
        _DWORD *a5,
        unsigned __int8 *a6,
        unsigned __int16 a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15)
{
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  int v28; // w23
  __int64 v29; // x0
  __int64 v30; // x1
  __int64 v31; // x2
  unsigned __int16 v32; // w3
  __int64 result; // x0
  unsigned __int8 *vendor_ie_ptr_from_oui; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned __int8 *v43; // x22
  unsigned __int8 noa_attr_stream; // w0
  unsigned __int8 v45; // w21
  _BYTE n[68]; // [xsp+Ch] [xbp-174h] BYREF
  _QWORD v47[5]; // [xsp+50h] [xbp-130h] BYREF
  _QWORD v48[30]; // [xsp+78h] [xbp-108h] BYREF
  _QWORD v49[3]; // [xsp+168h] [xbp-18h]

  v49[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_QWORD *)((char *)v49 + 7) = 0;
  v49[0] = 0;
  *(_WORD *)n = a7;
  memset(v48, 0, sizeof(v48));
  memset(v47, 0, 37);
  memset(&n[4], 0, 61);
  if ( (unsigned int)a7 - 1 > 0xFE || a7 > a4 )
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: addn_ielen %d exceed left %d",
               a8,
               a9,
               a10,
               a11,
               a12,
               a13,
               a14,
               a15,
               "sch_append_addn_ie",
               a7,
               a4);
LABEL_15:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  qdf_mem_set(&n[4], 0x3Du, 0);
  v28 = lim_strip_ie(
          a1,
          a6,
          (unsigned __int16 *)n,
          0xDDu,
          1,
          &unk_969516,
          4u,
          &n[4],
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          59);
  qdf_mem_copy(v48, a6, *(unsigned __int16 *)n);
  if ( v28 || n[4] != 221 )
  {
    v32 = *(_WORD *)n;
LABEL_10:
    vendor_ie_ptr_from_oui = wlan_get_vendor_ie_ptr_from_oui(&unk_969516, 4u, (unsigned __int8 *)v48, v32);
    if ( vendor_ie_ptr_from_oui )
    {
      if ( !*(_BYTE *)(a1 + 21576) )
      {
        v43 = vendor_ie_ptr_from_oui;
        noa_attr_stream = lim_get_noa_attr_stream(a1, (__int64)v47, a2);
        if ( noa_attr_stream )
        {
          if ( *(unsigned __int16 *)n + (unsigned int)noa_attr_stream > 0xFF )
          {
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: Not able to insert NoA because of length constraint",
              v35,
              v36,
              v37,
              v38,
              v39,
              v40,
              v41,
              v42,
              "sch_append_addn_ie");
          }
          else
          {
            v45 = noa_attr_stream;
            qdf_mem_copy((char *)v48 + *(unsigned __int16 *)n, v47, noa_attr_stream);
            *(_WORD *)n += v45;
            v43[1] += v45;
          }
        }
      }
    }
    if ( *(unsigned __int16 *)n > 0xFFu )
    {
      result = qdf_trace_msg(
                 0x35u,
                 3u,
                 "%s: Not able to insert because of len constraint %d",
                 v35,
                 v36,
                 v37,
                 v38,
                 v39,
                 v40,
                 v41,
                 v42,
                 "sch_append_addn_ie");
    }
    else
    {
      result = (__int64)qdf_mem_copy(a3, v48, *(unsigned __int16 *)n);
      *a5 += *(unsigned __int16 *)n;
    }
    goto LABEL_15;
  }
  v29 = qdf_mem_cmp(&n[6], &unk_969516, 4u);
  v32 = *(_WORD *)n;
  if ( (_DWORD)v29 )
    goto LABEL_10;
  if ( *(unsigned __int16 *)n <= 0xFFu )
  {
    qdf_mem_copy((char *)v48 + *(unsigned __int16 *)n, &n[4], (unsigned int)n[5] + 2);
    v32 = n[5] + *(_WORD *)n + 2;
    *(_WORD *)n = v32;
    goto LABEL_10;
  }
  __break(0x5512u);
  return sch_get_p2p_ie_offset(v29, v30, v31);
}
