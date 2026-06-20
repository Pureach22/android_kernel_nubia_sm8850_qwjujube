_BYTE *__fastcall mlo_roam_copy_partner_info(
        _BYTE *result,
        __int64 a2,
        unsigned __int8 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned int v12; // w8
  char v13; // w19
  unsigned __int64 v15; // x26
  unsigned int v16; // w20
  unsigned int v17; // w21
  _BYTE *v18; // x27
  int *v19; // x28
  int v20; // w12
  __int64 v21; // x7
  int v22; // w11
  unsigned __int8 *v23; // x13
  int v24; // w8
  int v25; // w9
  int v26; // w11
  int v27; // w10
  __int64 v28; // [xsp+0h] [xbp-20h]
  __int64 v29; // [xsp+8h] [xbp-18h]
  __int64 v30; // [xsp+10h] [xbp-10h]
  _BYTE *v31; // [xsp+18h] [xbp-8h]

  if ( !a2 )
    return result;
  v12 = *(unsigned __int8 *)(a2 + 2497);
  v13 = a4;
  if ( *(_BYTE *)(a2 + 2497) )
  {
    v15 = 0;
    v16 = 0;
    v17 = a3;
    v18 = result + 8;
    v19 = (int *)(a2 + 2540);
    v31 = result;
    while ( 1 )
    {
      if ( (v13 & 1) != 0 )
        goto LABEL_11;
      if ( v15 >= 3 )
        goto LABEL_18;
      if ( *(v19 - 10) != v17 )
      {
LABEL_11:
        if ( v16 > 3 || v15 > 2 )
        {
LABEL_18:
          __break(0x5512u);
          if ( !a4 )
            JUMPOUT(0x6AFEA8);
          return (_BYTE *)mlo_roam_update_connected_links(result, a2);
        }
        v23 = &v18[48 * v16];
        v24 = *(v19 - 9);
        v23[6] = v24;
        v25 = *(v19 - 10);
        v23[12] = v25;
        v26 = *v19;
        *((_WORD *)v23 + 2) = *((_WORD *)v19 + 2);
        *(_DWORD *)v23 = v26;
        v27 = *(v19 - 7);
        *((_WORD *)v23 + 5) = v27;
        if ( v23 )
        {
          v21 = *v23;
          v22 = v23[1];
          v20 = v23[2];
          LODWORD(v23) = v23[5];
        }
        else
        {
          v20 = 0;
          v21 = 0;
          v22 = 0;
        }
        LODWORD(v30) = (_DWORD)v23;
        LODWORD(v29) = v20;
        LODWORD(v28) = v22;
        result = (_BYTE *)qdf_trace_msg(
                            0x8Fu,
                            8u,
                            "%s: vdev_id %d link_id %d freq %d bssid%02x:%02x:%02x:**:**:%02x",
                            a5,
                            a6,
                            a7,
                            a8,
                            a9,
                            a10,
                            a11,
                            a12,
                            "mlo_roam_copy_partner_info",
                            (unsigned __int8)v25,
                            (unsigned __int8)v24,
                            (unsigned __int16)v27,
                            v21,
                            v28,
                            v29,
                            v30);
        v12 = *(unsigned __int8 *)(a2 + 2497);
        ++v16;
      }
      ++v15;
      v19 += 13;
      if ( v15 >= v12 )
      {
        result = v31;
        goto LABEL_16;
      }
    }
  }
  v16 = 0;
  v17 = a3;
LABEL_16:
  *result = v16;
  return (_BYTE *)qdf_trace_msg(
                    0x8Fu,
                    8u,
                    "%s: vdev_to_skip:%d num_setup_links %d fill_all_links:%d",
                    a5,
                    a6,
                    a7,
                    a8,
                    a9,
                    a10,
                    a11,
                    a12,
                    "mlo_roam_copy_partner_info",
                    v17,
                    v16,
                    v13 & 1);
}
