__int64 __fastcall dp_srng_msi_setup(_QWORD *a1, __int64 a2, __int64 a3, unsigned int a4, unsigned int a5)
{
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _BYTE *v21; // x24
  _BYTE *v22; // x8
  char v23; // w9
  int v24; // w9
  int v25; // w24
  int v26; // w25
  __int64 v27; // x8
  __int64 v28; // x0
  int v29; // w8
  int v30; // w10
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  _DWORD *v39; // x8
  __int64 v40; // x2
  unsigned int v41; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v42; // [xsp+8h] [xbp-18h] BYREF
  int v43; // [xsp+10h] [xbp-10h] BYREF
  int v44; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v45; // [xsp+18h] [xbp-8h]

  v45 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = a1[3];
  v44 = 0;
  v43 = 0;
  v11 = *(_QWORD *)(v10 + 40);
  v42 = 0;
  v41 = 0;
  result = pld_get_user_msi_assignment(v11, (__int64)"DP", (__int64)&v44, (__int64)&v43, (__int64)&v42 + 4);
  if ( !(_DWORD)result )
  {
    v21 = (_BYTE *)a1[5];
    switch ( a4 )
    {
      case 0u:
        v22 = v21 + 170;
        goto LABEL_17;
      case 1u:
        v22 = v21 + 278;
        goto LABEL_17;
      case 4u:
        v22 = v21 + 314;
        goto LABEL_17;
      case 0xDu:
        if ( a5 == (unsigned __int8)wlan_cfg_get_rx_rel_ring_id(a1[5]) )
        {
          v23 = 0;
          v22 = v21 + 296;
        }
        else if ( a5 == 6 )
        {
          v23 = 0;
          v22 = v21 + 440;
        }
        else
        {
          v22 = (_BYTE *)(a1[5] + 152LL);
LABEL_17:
          v23 = a5;
        }
        v24 = 1 << v23;
        if ( ((unsigned __int8)v24 & *v22) != 0 )
        {
          v25 = 0;
        }
        else if ( ((unsigned __int8)v24 & v22[1]) != 0 )
        {
          v25 = 1;
        }
        else if ( ((unsigned __int8)v24 & v22[2]) != 0 )
        {
          v25 = 2;
        }
        else if ( ((unsigned __int8)v24 & v22[3]) != 0 )
        {
          v25 = 3;
        }
        else if ( ((unsigned __int8)v24 & v22[4]) != 0 )
        {
          v25 = 4;
        }
        else if ( ((unsigned __int8)v24 & v22[5]) != 0 )
        {
          v25 = 5;
        }
        else if ( ((unsigned __int8)v24 & v22[6]) != 0 )
        {
          v25 = 6;
        }
        else if ( ((unsigned __int8)v24 & v22[7]) != 0 )
        {
          v25 = 7;
        }
        else if ( ((unsigned __int8)v24 & v22[8]) != 0 )
        {
          v25 = 8;
        }
        else if ( ((unsigned __int8)v24 & v22[9]) != 0 )
        {
          v25 = 9;
        }
        else if ( ((unsigned __int8)v24 & v22[10]) != 0 )
        {
          v25 = 10;
        }
        else if ( ((unsigned __int8)v24 & v22[11]) != 0 )
        {
          v25 = 11;
        }
        else if ( ((unsigned __int8)v24 & v22[12]) != 0 )
        {
          v25 = 12;
        }
        else if ( ((unsigned __int8)v24 & v22[13]) != 0 )
        {
          v25 = 13;
        }
        else if ( ((unsigned __int8)v24 & v22[14]) != 0 )
        {
          v25 = 14;
        }
        else if ( ((unsigned __int8)v24 & v22[15]) != 0 )
        {
          v25 = 15;
        }
        else if ( ((unsigned __int8)v24 & v22[16]) != 0 )
        {
          v25 = 16;
        }
        else
        {
          if ( ((unsigned __int8)v24 & v22[17]) == 0 )
          {
LABEL_68:
            result = qdf_trace_msg(
                       0x7Cu,
                       5u,
                       "%s: %pK: ring not part of an ext_group; ring_type: %d,ring_num %d",
                       v13,
                       v14,
                       v15,
                       v16,
                       v17,
                       v18,
                       v19,
                       v20,
                       "dp_srng_msi_setup",
                       a1,
                       a4,
                       a5);
            *(_QWORD *)(a3 + 24) = 0;
            *(_DWORD *)(a3 + 32) = 0;
            break;
          }
          v25 = 17;
        }
        v26 = v44;
        if ( (!a1 || (v27 = a1[3]) == 0 || (v28 = *(_QWORD *)(v27 + 40)) == 0 || (pld_is_one_msi(v28) & 1) == 0)
          && v25 > v26 )
        {
          qdf_trace_msg(
            0x7Cu,
            3u,
            "%s: %pK: 2 msi_groups will share an msi; msi_group_num %d",
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            "dp_srng_msi_setup",
            a1,
            (unsigned int)v25);
        }
        pld_get_msi_address(*(_QWORD *)(a1[3] + 40LL), (__int64)&v42, (__int64)&v41);
        v29 = v44;
        v30 = *(_DWORD *)(a3 + 48);
        *(_QWORD *)(a3 + 24) = (unsigned int)v42 | ((unsigned __int64)v41 << 32);
        *(_DWORD *)(a3 + 32) = v43 + v25 % v29;
        *(_DWORD *)(a3 + 48) = v30 | 0x20000;
        result = qdf_trace_msg(
                   0x45u,
                   8u,
                   "%s: ring type %u ring_num %u msi->data %u msi_addr %llx",
                   v31,
                   v32,
                   v33,
                   v34,
                   v35,
                   v36,
                   v37,
                   v38,
                   "dp_srng_msi_setup",
                   a4,
                   a5);
        v39 = (_DWORD *)a1[212];
        if ( v39 )
        {
          v40 = (unsigned int)(v25 % v44 + HIDWORD(v42));
          if ( *(v39 - 1) != -1171869274 )
            __break(0x8228u);
          result = ((__int64 (__fastcall *)(_QWORD *, __int64, __int64, _QWORD, _QWORD))v39)(a1, a2, v40, a4, a5);
        }
        break;
      case 0xEu:
        v22 = v21 + 350;
        goto LABEL_17;
      case 0xFu:
        v22 = v21 + 332;
        goto LABEL_17;
      case 0x10u:
        v22 = v21 + 224;
        goto LABEL_17;
      case 0x11u:
      case 0x12u:
        v22 = v21 + 188;
        goto LABEL_17;
      case 0x15u:
        v22 = v21 + 476;
        goto LABEL_17;
      case 0x16u:
        v22 = v21 + 458;
        goto LABEL_17;
      case 0x18u:
        v22 = v21 + 422;
        goto LABEL_17;
      case 0x19u:
        v22 = v21 + 206;
        goto LABEL_17;
      case 0x1Cu:
        v22 = v21 + 152;
        goto LABEL_17;
      default:
        goto LABEL_68;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
