__int64 __fastcall wlan_dp_resource_mgr_notify_ndp_channel_info(
        __int64 result,
        __int64 a2,
        __int64 a3,
        int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x8
  int v14; // w21
  __int64 v15; // x19
  unsigned __int64 v17; // x24
  unsigned __int64 v18; // x23
  int v19; // w26
  int v20; // w28
  int v21; // w0
  unsigned int v22; // w8
  const char *v23; // x2
  unsigned __int64 StatusReg; // x8
  __int64 comp_private_obj; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x20
  unsigned int v35; // w1
  __int64 v36; // x8
  _QWORD *v37; // x1
  _QWORD *v38; // x0
  int v39; // w0
  __int64 v40; // x21
  __int64 v41; // x0
  __int64 v42; // x20
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  _QWORD *v51; // x1
  _QWORD *v52; // x0
  int v53; // w0
  __int64 v54; // x8
  _QWORD *v55; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v56[2]; // [xsp+10h] [xbp-10h] BYREF

  v56[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result )
  {
    v12 = *(_QWORD *)(a2 + 88);
    if ( v12 )
    {
      if ( *(_DWORD *)(v12 + 16) == 11 )
      {
        v14 = a4;
        v15 = result;
        if ( a4 )
        {
          v17 = 0;
          v18 = 0;
          v19 = 0;
          v20 = 0;
          while ( 1 )
          {
            v21 = wma_fw_to_host_phymode(*(_DWORD *)a3);
            v22 = v21 - 1;
            if ( *(_BYTE *)(a3 + 16) )
            {
              if ( v22 > 0x1D )
              {
                if ( v17 < 0x960 )
                {
LABEL_17:
                  v19 = v21;
                  v17 = 54;
                  switch ( v21 )
                  {
                    case 1:
                    case 3:
                    case 4:
                      break;
                    case 2:
                      v17 = 12;
                      goto LABEL_7;
                    case 5:
                    case 6:
                      v17 = 150;
                      goto LABEL_7;
                    case 7:
                    case 8:
                    case 9:
                    case 10:
                    case 21:
                    case 22:
                      v17 = 300;
                      goto LABEL_7;
                    case 11:
                    case 12:
                      v17 = 275;
                      goto LABEL_7;
                    case 13:
                    case 14:
                    case 15:
                    case 16:
                      v17 = 550;
                      goto LABEL_7;
                    case 17:
                    case 18:
                      v17 = 1100;
                      goto LABEL_7;
                    case 19:
                    case 20:
                      v17 = 2200;
                      goto LABEL_7;
                    case 23:
                    case 24:
                    case 25:
                    case 26:
                      v17 = 600;
                      goto LABEL_7;
                    case 27:
                    case 28:
                      v17 = 1200;
                      goto LABEL_7;
                    case 29:
                    case 30:
                      v17 = 2400;
LABEL_7:
                      v19 = v21;
                      break;
                    default:
                      v19 = v21;
                      v17 = 2400;
                      break;
                  }
                }
              }
              else if ( (unsigned __int64)(&off_A2EC58)[v22] > v17 )
              {
                goto LABEL_17;
              }
            }
            else if ( v22 > 0x1D )
            {
              if ( v18 < 0x960 )
              {
LABEL_20:
                v20 = v21;
                v18 = 54;
                switch ( v21 )
                {
                  case 1:
                  case 3:
                  case 4:
                    break;
                  case 2:
                    v18 = 12;
                    v20 = v21;
                    break;
                  case 5:
                  case 6:
                    v18 = 150;
                    v20 = v21;
                    break;
                  case 7:
                  case 8:
                  case 9:
                  case 10:
                  case 21:
                  case 22:
                    v18 = 300;
                    v20 = v21;
                    break;
                  case 11:
                  case 12:
                    v18 = 275;
                    v20 = v21;
                    break;
                  case 13:
                  case 14:
                  case 15:
                  case 16:
                    v18 = 550;
                    v20 = v21;
                    break;
                  case 17:
                  case 18:
                    v18 = 1100;
                    v20 = v21;
                    break;
                  case 19:
                  case 20:
                    v18 = 2200;
                    v20 = v21;
                    break;
                  case 23:
                  case 24:
                  case 25:
                  case 26:
                    v18 = 600;
                    v20 = v21;
                    break;
                  case 27:
                  case 28:
                    v18 = 1200;
                    v20 = v21;
                    break;
                  case 29:
                  case 30:
                    v18 = 2400;
                    v20 = v21;
                    break;
                  default:
                    v20 = v21;
                    v18 = 2400;
                    break;
                }
              }
            }
            else if ( (unsigned __int64)(&off_A2EC58)[v22] > v18 )
            {
              goto LABEL_20;
            }
            --v14;
            a3 += 20;
            if ( !v14 )
              goto LABEL_44;
          }
        }
        v20 = 0;
        v19 = 0;
        v18 = 0;
        v17 = 0;
LABEL_44:
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v15 + 216);
        }
        else
        {
          raw_spin_lock_bh(v15 + 216);
          *(_QWORD *)(v15 + 224) |= 1uLL;
        }
        comp_private_obj = wlan_objmgr_peer_get_comp_private_obj(a2, 0x2Eu);
        if ( comp_private_obj )
        {
          v34 = *(_QWORD *)(comp_private_obj + 24);
          if ( v34 )
          {
            if ( *(_DWORD *)(v34 + 44) == v20 && *(_DWORD *)(v34 + 48) == v19 )
            {
              qdf_spin_unlock_bh_25(v15 + 216);
              v23 = "%s: NDP Max phymode did not change";
              v35 = 5;
LABEL_57:
              result = qdf_trace_msg(
                         0x45u,
                         v35,
                         v23,
                         a5,
                         a6,
                         a7,
                         a8,
                         a9,
                         a10,
                         a11,
                         a12,
                         "wlan_dp_resource_mgr_notify_ndp_channel_info");
              goto LABEL_58;
            }
            *(_DWORD *)(v34 + 44) = v20;
            *(_DWORD *)(v34 + 48) = v19;
            *(_QWORD *)(v34 + 80) = v18;
            *(_QWORD *)(v34 + 88) = v17;
            qdf_list_remove_node(v15 + 112, (_QWORD *)(v34 + 56));
            v55 = nullptr;
            v56[0] = 0;
            if ( !(unsigned int)qdf_list_peek_front((_QWORD *)(v15 + 112), v56) )
            {
              v37 = (_QWORD *)v56[0];
              while ( 1 )
              {
                v38 = (_QWORD *)(v15 + 112);
                if ( *(_QWORD *)(v34 + 80) > v37[3] )
                  break;
                v39 = qdf_list_peek_next(v38, v37, &v55);
                v37 = v55;
                v55 = nullptr;
                v56[0] = v37;
                if ( v39 )
                  goto LABEL_73;
              }
              qdf_list_insert_before((__int64)v38, (_QWORD *)(v34 + 56), v37);
            }
            v37 = (_QWORD *)v56[0];
LABEL_73:
            if ( !v37 )
              qdf_list_insert_back((_QWORD *)(v15 + 112), (_QWORD *)(v34 + 56));
            goto LABEL_80;
          }
          v40 = comp_private_obj;
          v41 = _qdf_mem_malloc(0x70u, "wlan_dp_resource_mgr_notify_ndp_channel_info", 806);
          if ( v41 )
          {
            v42 = v41;
            *(_QWORD *)(v40 + 24) = v41;
            *(_DWORD *)(v41 + 44) = v20;
            *(_DWORD *)(v41 + 48) = v19;
            *(_QWORD *)(v41 + 80) = v18;
            *(_QWORD *)(v41 + 88) = v17;
            *(_BYTE *)(v41 + 104) = 1;
            v55 = nullptr;
            v56[0] = 0;
            if ( !(unsigned int)qdf_list_peek_front((_QWORD *)(v15 + 112), v56) )
            {
              v51 = (_QWORD *)v56[0];
              while ( 1 )
              {
                v52 = (_QWORD *)(v15 + 112);
                if ( *(_QWORD *)(v42 + 80) > v51[3] )
                  break;
                v53 = qdf_list_peek_next(v52, v51, &v55);
                v51 = v55;
                v55 = nullptr;
                v56[0] = v51;
                if ( v53 )
                  goto LABEL_77;
              }
              qdf_list_insert_before((__int64)v52, (_QWORD *)(v42 + 56), v51);
            }
            v51 = (_QWORD *)v56[0];
LABEL_77:
            if ( !v51 )
              qdf_list_insert_back((_QWORD *)(v15 + 112), (_QWORD *)(v42 + 56));
            qdf_trace_msg(
              0x45u,
              5u,
              "%s: NDP new node phymode0:%u tput0:%llu phymode1:%u tput1:%llu list_len:%u",
              v43,
              v44,
              v45,
              v46,
              v47,
              v48,
              v49,
              v50,
              "wlan_dp_resource_mgr_notify_ndp_channel_info",
              *(unsigned int *)(v42 + 44),
              *(_QWORD *)(v42 + 80),
              *(unsigned int *)(v42 + 48),
              *(_QWORD *)(v42 + 88),
              *(_DWORD *)(v15 + 128));
LABEL_80:
            ((void (__fastcall *)(__int64))wlan_dp_resource_mgr_select_max_phymodes)(v15);
            v54 = *(_QWORD *)(v15 + 224);
            if ( (v54 & 1) != 0 )
            {
              *(_QWORD *)(v15 + 224) = v54 & 0xFFFFFFFFFFFFFFFELL;
              result = raw_spin_unlock_bh(v15 + 216);
            }
            else
            {
              result = raw_spin_unlock(v15 + 216);
            }
            goto LABEL_58;
          }
          qdf_spin_unlock_bh_25(v15 + 216);
          v23 = "%s: Failed to allocate memory for resource vote node";
        }
        else
        {
          qdf_trace_msg(0x45u, 2u, "%s: peer is null", v26, v27, v28, v29, v30, v31, v32, v33, "dp_get_peer_priv_obj");
          v36 = *(_QWORD *)(v15 + 224);
          if ( (v36 & 1) != 0 )
          {
            *(_QWORD *)(v15 + 224) = v36 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v15 + 216);
          }
          else
          {
            raw_spin_unlock(v15 + 216);
          }
          v23 = "%s: DP peer priv ctx not present";
        }
      }
      else
      {
        v23 = "%s: NDP channel notify came for peer/vdev opmode not proper";
      }
    }
    else
    {
      v23 = "%s: unable to get vdev ref from peer";
    }
    v35 = 2;
    goto LABEL_57;
  }
LABEL_58:
  _ReadStatusReg(SP_EL0);
  return result;
}
