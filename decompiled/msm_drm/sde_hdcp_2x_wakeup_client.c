__int64 __fastcall sde_hdcp_2x_wakeup_client(
        __int64 result,
        unsigned int *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  _QWORD *v8; // x8
  unsigned int v9; // w8
  __int64 v10; // x19
  unsigned int *v11; // x20
  unsigned int *v12; // x22
  unsigned int v13; // w8
  unsigned int v14; // w8
  int v15; // w8
  unsigned int *v16; // x20
  __int64 (__fastcall *v17)(_QWORD); // x8
  int v18; // w9
  __int64 v19; // x1
  __int64 v20; // x1
  __int64 v21; // x2
  __int64 v22; // x3
  __int64 v23; // x4
  __int64 v24; // x5
  __int64 v25; // x6
  int v26; // w7
  char vars0; // [xsp+0h] [xbp+0h]

  if ( result )
  {
    v8 = *(_QWORD **)(result + 160);
    if ( v8 )
    {
      if ( a2 )
      {
        if ( *v8 )
        {
          v9 = *a2;
          if ( *a2 )
          {
            v10 = result;
            *((_BYTE *)a2 + 36) = 24;
            if ( v9 <= 5 && ((1 << v9) & 0x26) != 0 )
            {
              v11 = (unsigned int *)(result + 172);
              v12 = a2;
              sde_evtlog_log(
                sde_dbg_base_evtlog,
                "sde_hdcp_2x_get_next_message",
                156,
                8,
                4369,
                *(_DWORD *)(result + 172),
                -1059143953,
                a8,
                vars0);
              a2 = v12;
              result = v10;
              v13 = 2;
              switch ( *v11 )
              {
                case 0u:
                  goto LABEL_30;
                case 2u:
                  v13 = 3;
                  goto LABEL_30;
                case 3u:
                  if ( *(_BYTE *)(v10 + 136) )
                    v13 = 4;
                  else
                    v13 = 5;
                  goto LABEL_30;
                case 4u:
                case 5u:
                  v13 = 7;
                  goto LABEL_30;
                case 7u:
                  if ( *(_BYTE *)(v10 + 136) )
                    v13 = 8;
                  else
                    v13 = 9;
                  goto LABEL_30;
                case 8u:
                  v13 = 9;
                  goto LABEL_30;
                case 9u:
                  v13 = 10;
                  goto LABEL_30;
                case 0xAu:
                  if ( *(_BYTE *)(v10 + 140) )
                    v13 = 9;
                  else
                    v13 = 11;
                  goto LABEL_30;
                case 0xBu:
                case 0x12u:
                  if ( (*(_BYTE *)(v10 + 168) & 1) != 0 )
                    goto LABEL_11;
                  v13 = 18;
                  goto LABEL_30;
                case 0xCu:
                  v13 = 15;
                  goto LABEL_30;
                case 0xFu:
                case 0x11u:
LABEL_11:
                  if ( *(_BYTE *)(v10 + 168) != 1 )
                    goto LABEL_54;
                  if ( *v12 == 1 )
                    v13 = 16;
                  else
                    v13 = 12;
LABEL_30:
                  *v11 = v13;
                  *((_QWORD *)v12 + 5) = &hdcp_msg_lookup[20 * v13];
                  break;
                case 0x10u:
                  *(_BYTE *)(v10 + 141) = 0;
                  v13 = 17;
                  goto LABEL_30;
                default:
                  result = printk(&unk_260CC5, "sde_hdcp_2x_get_next_message");
                  goto LABEL_54;
              }
            }
            v14 = *(_DWORD *)(result + 172);
            if ( v14 == 3 )
            {
              v15 = 50;
            }
            else
            {
              if ( v14 == 17 )
                goto LABEL_36;
              v15 = 0;
            }
            a2[7] = v15;
            v14 = *(_DWORD *)(result + 172);
            if ( v14 >= 0x13 )
            {
              __break(0x5512u);
              return ((__int64 (*)(void))hdcp_transport_cmd_to_str)();
            }
LABEL_36:
            v16 = a2;
            a2[8] = hdcp_msg_lookup[20 * v14 + 19];
            v17 = **(__int64 (__fastcall ***)(_QWORD))(result + 160);
            if ( *((_DWORD *)v17 - 1) != 805509580 )
              __break(0x8228u);
            result = v17(a2);
            if ( (_DWORD)result )
            {
              hdcp_transport_cmd_to_str(*v16);
              result = printk(&unk_25CF0B, "sde_hdcp_2x_wakeup_client");
            }
            v18 = *(_DWORD *)(v10 + 172);
            switch ( v18 )
            {
              case 12:
                v11 = (unsigned int *)(v10 + 124);
                if ( (*(_BYTE *)(v10 + 139) & 1) == 0 )
                {
                  v19 = 750;
                  *v11 = 750;
                  if ( *(_DWORD *)(v10 + 176) )
                    return result;
                  goto LABEL_47;
                }
                break;
              case 8:
                goto LABEL_45;
              case 7:
                if ( *(_BYTE *)(v10 + 136) == 1 )
                {
                  v19 = 250;
                  goto LABEL_46;
                }
LABEL_45:
                v19 = 62;
LABEL_46:
                *(_DWORD *)(v10 + 124) = v19;
                if ( *(_DWORD *)(v10 + 176) )
                  return result;
LABEL_47:
                v11 = (unsigned int *)(v10 + 124);
                *(_DWORD *)(v10 + 224) = 0;
                result = wait_for_completion_timeout(v10 + 224, v19);
                if ( !(_DWORD)result )
                {
                  sde_hdcp_2x_message_name(*(unsigned int *)(v10 + 172));
                  result = printk(&unk_25CF3B, "sde_hdcp_2x_wait_for_response");
                  if ( !*(_DWORD *)(v10 + 176) )
                    result = sde_hdcp_2x_clean(v10, v20, v21, v22, v23, v24, v25, v26);
                }
                break;
              default:
                v11 = (unsigned int *)(v10 + 124);
                break;
            }
LABEL_54:
            *v11 = 0;
          }
        }
      }
    }
  }
  return result;
}
