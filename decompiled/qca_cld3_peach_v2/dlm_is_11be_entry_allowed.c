__int64 __fastcall dlm_is_11be_entry_allowed(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        _QWORD *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v13; // x4
  __int64 v14; // x5
  __int64 v15; // x6
  __int64 v16; // x7
  int v17; // w8
  int v18; // w9
  int v19; // w10
  int v20; // w11
  int v21; // w12
  const char *v22; // x2
  __int64 result; // x0
  bool v26; // zf
  bool v27; // zf
  bool v28; // zf
  __int64 v30; // x8
  _QWORD *v31; // x1
  int v32; // w26
  char *v33; // x4
  unsigned int v34; // w8
  int v36; // w25
  __int64 pdev_obj; // x24
  __int64 psoc_obj; // x0
  int v39; // w8
  int v40; // [xsp+0h] [xbp-50h]
  int v41; // [xsp+8h] [xbp-48h]
  int v42; // [xsp+10h] [xbp-40h]
  int v43; // [xsp+18h] [xbp-38h]
  int v44; // [xsp+20h] [xbp-30h]
  _QWORD *v46; // [xsp+38h] [xbp-18h] BYREF
  _QWORD v47[2]; // [xsp+40h] [xbp-10h] BYREF

  v47[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_QWORD *)(a2 + 1824) )
    goto LABEL_51;
  if ( *(_BYTE *)(a3 + 49) == 16 )
  {
    v13 = *(unsigned __int8 *)(a2 + 1);
    v14 = *(unsigned __int8 *)(a2 + 2);
    v15 = *(unsigned __int8 *)(a2 + 3);
    v16 = *(unsigned __int8 *)(a2 + 6);
    v17 = *(unsigned __int8 *)(a2 + 1918);
    v18 = *(unsigned __int8 *)(a3 + 16);
    v19 = *(unsigned __int8 *)(a3 + 17);
    v20 = *(unsigned __int8 *)(a3 + 18);
    v21 = *(unsigned __int8 *)(a3 + 21);
    v22 = "%s: %02x:%02x:%02x:**:**:%02x with no of links %d, rejected as bssid %02x:%02x:%02x:**:**:%02x is not allowed for 11BE";
LABEL_4:
    v44 = v21;
    v43 = v20;
    v42 = v19;
    v41 = v18;
LABEL_5:
    v40 = v17;
LABEL_6:
    qdf_trace_msg(
      0x6Du,
      8u,
      v22,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "dlm_is_11be_entry_allowed",
      v13,
      v14,
      v15,
      v16,
      v40,
      v41,
      v42,
      v43,
      v44);
    result = 0;
LABEL_52:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( !*(_BYTE *)(a2 + 1918) )
    goto LABEL_30;
  v26 = *(_DWORD *)(a3 + 16) == *(_DWORD *)(a2 + 1920)
     && *(unsigned __int16 *)(a3 + 20) == *(unsigned __int16 *)(a2 + 1924);
  if ( v26 && *(_BYTE *)(a3 + 49) == 2 )
    goto LABEL_28;
  if ( *(unsigned __int8 *)(a2 + 1918) < 2u )
    goto LABEL_30;
  v27 = *(_DWORD *)(a3 + 16) == *(_DWORD *)(a2 + 1968)
     && *(unsigned __int16 *)(a3 + 20) == *(unsigned __int16 *)(a2 + 1972);
  if ( v27 && *(_BYTE *)(a3 + 49) == 2 )
    goto LABEL_28;
  if ( *(unsigned __int8 *)(a2 + 1918) < 3u )
    goto LABEL_30;
  v28 = *(_DWORD *)(a3 + 16) == *(_DWORD *)(a2 + 2016)
     && *(unsigned __int16 *)(a3 + 20) == *(unsigned __int16 *)(a2 + 2020);
  if ( v28 && *(_BYTE *)(a3 + 49) == 2 )
  {
LABEL_28:
    v21 = *(unsigned __int8 *)(a3 + 21);
    v13 = *(unsigned __int8 *)(a2 + 1);
    v14 = *(unsigned __int8 *)(a2 + 2);
    v15 = *(unsigned __int8 *)(a2 + 3);
    v16 = *(unsigned __int8 *)(a2 + 6);
    v17 = *(unsigned __int8 *)(a2 + 1918);
    v18 = *(unsigned __int8 *)(a3 + 16);
    v19 = *(unsigned __int8 *)(a3 + 17);
    v20 = *(unsigned __int8 *)(a3 + 18);
    v22 = "%s: %02x:%02x:%02x:**:**:%02x with no of links %d, rejected as partner link %02x:%02x:%02x:**:**:%02x is not allowed for 11BE";
    goto LABEL_4;
  }
  if ( *(unsigned __int8 *)(a2 + 1918) <= 3u )
  {
LABEL_30:
    if ( *(_DWORD *)(a3 + 16) == *(_DWORD *)(a2 + 1) && *(unsigned __int16 *)(a3 + 20) == *(unsigned __int16 *)(a2 + 5) )
    {
      v39 = *(unsigned __int8 *)(a2 + 1918);
      if ( v39 == 2 )
      {
        if ( *(_BYTE *)(a3 + 49) == 8 )
        {
          v13 = *(unsigned __int8 *)(a2 + 1);
          v14 = *(unsigned __int8 *)(a2 + 2);
          v22 = "%s: %02x:%02x:%02x:**:**:%02x with no of links %d, as 2 link not allowed ";
          v15 = *(unsigned __int8 *)(a2 + 3);
          v16 = *(unsigned __int8 *)(a2 + 6);
          v17 = 2;
          goto LABEL_5;
        }
      }
      else if ( v39 == 3 && *(_BYTE *)(a3 + 49) == 4 )
      {
        v13 = *(unsigned __int8 *)(a2 + 1);
        v14 = *(unsigned __int8 *)(a2 + 2);
        v22 = "%s: %02x:%02x:%02x:**:**:%02x with no of links %d, as 3 link not allowed ";
        v15 = *(unsigned __int8 *)(a2 + 3);
        v16 = *(unsigned __int8 *)(a2 + 6);
        v17 = 3;
        goto LABEL_5;
      }
    }
    v30 = *(_QWORD *)(a2 + 1824);
    v46 = nullptr;
    v47[0] = 0;
    if ( v30 )
    {
      qdf_list_peek_front(a4, v47);
      v31 = (_QWORD *)v47[0];
      if ( v47[0] )
      {
        v32 = 0;
        while ( 1 )
        {
          qdf_list_peek_next(a4, v31, &v46);
          if ( *(_DWORD *)(v47[0] + 22LL) == *(_DWORD *)(a2 + 1912)
            && *(unsigned __int16 *)(v47[0] + 26LL) == *(unsigned __int16 *)(a2 + 1916) )
          {
            v36 = *(unsigned __int8 *)(v47[0] + 48LL);
            pdev_obj = dlm_get_pdev_obj(a1);
            psoc_obj = dlm_get_psoc_obj(*(_QWORD *)(a1 + 80));
            if ( pdev_obj && psoc_obj )
            {
              v34 = *(unsigned __int8 *)(psoc_obj + 48);
            }
            else
            {
              v33 = pdev_obj ? "dlm_ctx" : "dlm_psoc_obj";
              qdf_trace_msg(
                0x6Du,
                2u,
                "%s: %s is NULL",
                a5,
                a6,
                a7,
                a8,
                a9,
                a10,
                a11,
                a12,
                "dlm_get_max_allowed_11be_failure",
                v33);
              v34 = 7;
            }
            v32 += v36;
            if ( v34 < (unsigned __int8)v32 )
              break;
          }
          v31 = v46;
          v46 = nullptr;
          v47[0] = v31;
          if ( !v31 )
            goto LABEL_51;
        }
        v22 = "%s: %02x:%02x:%02x:**:**:%02x MAX trial reach for the MLD %02x:%02x:%02x:**:**:%02x";
        v13 = *(unsigned __int8 *)(a3 + 16);
        v14 = *(unsigned __int8 *)(a3 + 17);
        v15 = *(unsigned __int8 *)(a3 + 18);
        v16 = *(unsigned __int8 *)(a3 + 21);
        v41 = *(unsigned __int8 *)(a3 + 23);
        v43 = *(unsigned __int8 *)(a3 + 27);
        v42 = *(unsigned __int8 *)(a3 + 24);
        v40 = *(unsigned __int8 *)(a3 + 22);
        goto LABEL_6;
      }
    }
LABEL_51:
    result = 1;
    goto LABEL_52;
  }
  __break(0x5512u);
  return dlm_try_delete_bssid_in_list(a1, a2, a3);
}
