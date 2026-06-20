__int64 __fastcall action_oui_search(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x22
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _QWORD *v21; // x25
  char v22; // w23
  int v23; // w20
  int v24; // w3
  unsigned __int8 *vendor_ie_ptr_from_oui; // x0
  int v26; // w8
  int v27; // w0
  unsigned __int8 *v28; // x27
  int v29; // w26
  __int64 v30; // x21
  unsigned int v31; // w8
  size_t v32; // x2
  int v33; // w0
  unsigned int v34; // w8
  __int64 v35; // x10
  unsigned __int8 v36; // w12
  unsigned __int64 v37; // x8
  unsigned __int8 v38; // w9
  int v39; // w13
  int v40; // w8
  int v41; // w10
  unsigned __int8 *v42; // x9
  __int64 result; // x0
  _QWORD *v44; // [xsp+8h] [xbp-18h] BYREF
  _QWORD *v45[2]; // [xsp+10h] [xbp-10h] BYREF

  v45[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  v44 = nullptr;
  v45[0] = nullptr;
  if ( a3 >= 0x1C )
LABEL_85:
    __break(0x5512u);
  v11 = *(_QWORD *)(a1 + 8LL * a3 + 23544);
  if ( !v11 )
  {
    qdf_trace_msg(
      0x63u,
      8u,
      "%s: action oui for id %d is empty",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "action_oui_search",
      a3);
    goto LABEL_83;
  }
  qdf_mutex_acquire(v11 + 32);
  if ( qdf_list_empty((_QWORD *)(v11 + 8)) )
    goto LABEL_82;
  qdf_list_peek_front((_QWORD *)(v11 + 8), v45);
  v21 = v45[0];
  if ( !v45[0] )
    goto LABEL_82;
  v22 = 0;
  while ( 1 )
  {
    if ( (v22 & 1) != 0 )
    {
      if ( !*((_BYTE *)v21 + 80) )
        goto LABEL_81;
    }
    else if ( *((_BYTE *)v21 + 80) )
    {
      goto LABEL_16;
    }
    v23 = *((_DWORD *)v21 + 4);
    if ( *(_QWORD *)a2 && (v24 = *(_DWORD *)(a2 + 8)) != 0 )
    {
      vendor_ie_ptr_from_oui = wlan_get_vendor_ie_ptr_from_oui(
                                 (char *)v21 + 44,
                                 *((_DWORD *)v21 + 5),
                                 *(unsigned __int8 **)a2,
                                 v24);
      v26 = v23 & 1;
      if ( vendor_ie_ptr_from_oui )
        goto LABEL_20;
    }
    else
    {
      v26 = v21[2] & 1;
    }
    if ( v26 )
      goto LABEL_16;
LABEL_20:
    if ( *((_DWORD *)v21 + 6) && v26 )
    {
      v28 = *(unsigned __int8 **)a2;
      if ( *(_QWORD *)a2 )
      {
        v29 = *(_DWORD *)(a2 + 8);
        if ( v29 >= 2 )
        {
          while ( 1 )
          {
            v30 = v28[1];
            v31 = v29 - 2;
            v29 = v29 - 2 - v30;
            if ( v31 < (unsigned int)v30 )
              break;
            if ( *v28 == 221 )
            {
              v32 = *((unsigned int *)v21 + 5);
              if ( (unsigned int)v32 > v31 )
                break;
              v33 = qdf_mem_cmp(v28 + 2, (char *)v21 + 44, v32);
              if ( v28 )
              {
                if ( !v33 )
                {
                  v34 = v28[1];
                  v35 = *((unsigned int *)v21 + 5);
                  if ( (unsigned int)v35 <= v34 )
                  {
                    v36 = v34 - v35;
                    if ( *((_DWORD *)v21 + 6) <= (unsigned int)(unsigned __int8)(v34 - v35) )
                    {
                      if ( v34 != (unsigned __int8)v35 )
                      {
                        v37 = 0;
                        v38 = 0;
                        LOBYTE(v39) = 0x80;
                        while ( *((_DWORD *)v21 + 7) > (unsigned int)v38 )
                        {
                          if ( v37 == 24 )
                            goto LABEL_85;
                          if ( ((unsigned __int8)v39 & *((_BYTE *)v21 + v38 + 69)) != 0 )
                          {
                            if ( v37 > 0x13 )
                              goto LABEL_85;
                            if ( *((unsigned __int8 *)v21 + v37 + 49) != v28[v35 + 2 + v37] )
                              goto LABEL_25;
                          }
                          ++v37;
                          v39 = (unsigned __int8)v39 >> 1;
                          if ( !v39 )
                          {
                            ++v38;
                            LOBYTE(v39) = 0x80;
                          }
                          if ( v36 == v37 )
                            goto LABEL_44;
                        }
                      }
                      goto LABEL_44;
                    }
                  }
                }
              }
            }
LABEL_25:
            v22 = 0;
            v28 += v30 + 2;
            if ( v29 <= 1 )
              goto LABEL_17;
          }
        }
      }
LABEL_16:
      v22 = 0;
      goto LABEL_17;
    }
LABEL_44:
    v40 = *((_DWORD *)v21 + 4);
    if ( (v40 & 2) != 0 )
    {
      v41 = *((char *)v21 + 78);
      v42 = *(unsigned __int8 **)(a2 + 16);
      if ( v41 < 0 && *((unsigned __int8 *)v21 + 72) != *v42 )
        goto LABEL_16;
      if ( (v41 & 0x40) != 0 && *((unsigned __int8 *)v21 + 73) != v42[1]
        || (v41 & 0x20) != 0 && *((unsigned __int8 *)v21 + 74) != v42[2]
        || (v41 & 0x10) != 0 && *((unsigned __int8 *)v21 + 75) != v42[3]
        || (v41 & 8) != 0 && *((unsigned __int8 *)v21 + 76) != v42[4]
        || (v41 & 4) != 0 && *((unsigned __int8 *)v21 + 77) != v42[5] )
      {
        goto LABEL_16;
      }
    }
    if ( (v40 & 4) != 0 && (((unsigned __int8)(*((_BYTE *)v21 + 79) & 0xF) >> (*(_BYTE *)(a2 + 24) - 1)) & 1) == 0 )
      goto LABEL_16;
    if ( (v40 & 8) != 0 )
    {
      if ( (*((_BYTE *)v21 + 79) & 0x10) != 0 )
      {
        if ( (*(_BYTE *)(a2 + 28) & 1) == 0 )
          goto LABEL_16;
      }
      else if ( (*(_BYTE *)(a2 + 28) & 1) != 0 )
      {
        goto LABEL_16;
      }
    }
    if ( (v40 & 0x10) != 0 )
    {
      if ( (*((_BYTE *)v21 + 79) & 0x20) != 0 )
      {
        if ( (*(_BYTE *)(a2 + 29) & 1) == 0 )
          goto LABEL_16;
      }
      else if ( (*(_BYTE *)(a2 + 29) & 1) != 0 )
      {
        goto LABEL_16;
      }
    }
    if ( (v40 & 0x20) != 0
      && (*(_BYTE *)(a2 + 31) == 1 && (*((char *)v21 + 79) & 0x80000000) == 0
       || *(_BYTE *)(a2 + 30) == 1 && (*((_BYTE *)v21 + 79) & 0x40) == 0) )
    {
      goto LABEL_16;
    }
    qdf_trace_msg(
      0x63u,
      8u,
      "%s: Vendor AP/STA found for OUI",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "action_oui_search");
    ((void (__fastcall *)(__int64, __int64, char *, _QWORD))qdf_trace_hex_dump)(
      53,
      8,
      (char *)v21 + 44,
      *((unsigned int *)v21 + 5));
    v22 = 1;
LABEL_17:
    v27 = qdf_list_peek_next((_QWORD *)(v11 + 8), v45[0], &v44);
    if ( v27 )
      break;
    v21 = v44;
    v44 = nullptr;
    v45[0] = v21;
    if ( !v21 )
      goto LABEL_82;
  }
  if ( v27 == 13 && (v22 & 1) != 0 )
  {
LABEL_81:
    qdf_mutex_release(v11 + 32);
    result = 1;
    goto LABEL_84;
  }
LABEL_82:
  qdf_mutex_release(v11 + 32);
LABEL_83:
  result = 0;
LABEL_84:
  _ReadStatusReg(SP_EL0);
  return result;
}
