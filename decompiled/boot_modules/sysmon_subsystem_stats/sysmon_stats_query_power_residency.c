__int64 __fastcall sysmon_stats_query_power_residency(int a1, _DWORD *a2)
{
  void *v4; // x0
  __int64 result; // x0
  _BYTE *v6; // x20
  unsigned __int64 v7; // x21
  __int64 (*v8)(void); // x8
  __int64 *v9; // x23
  __int64 (*v10)(void); // x8
  unsigned __int64 v11; // x22
  __int64 v12; // x8
  __int64 (*v13)(void); // x8
  __int64 (*v14)(void); // x8
  __int64 v15; // x0
  __int64 v16; // x8
  __int64 (*v17)(void); // x8
  unsigned __int64 v18; // x8
  unsigned __int64 StatusReg; // x9
  unsigned __int64 v20; // x8
  unsigned __int64 v21; // x8
  unsigned __int64 v22; // x13
  __int64 v23; // x10
  unsigned __int64 v24; // x10
  int v25; // w9
  __int64 v26; // x11
  __int64 v27; // x12
  int v28; // w12
  __int64 v29; // x13
  void *v30; // x0
  _DWORD *v31; // x13
  int v32; // w14
  int v33; // w8
  int v34; // w9
  _DWORD s[100]; // [xsp+8h] [xbp-198h] BYREF
  __int64 v36; // [xsp+198h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = memset(s, 0, sizeof(s));
  if ( !a2 )
  {
    printk(&unk_9E79, "sysmon_subsystem_stats");
    goto LABEL_78;
  }
  switch ( a1 )
  {
    case 5:
      if ( (byte_9601 & 1) == 0 )
        sysmon_smem_init_cdsp();
      result = 4294967170LL;
      v6 = (_BYTE *)qword_9610;
      if ( qword_9610 && (unsigned __int64)qword_9610 <= 0xFFFFFFFFFFFFF000LL )
      {
        if ( !(unsigned int)copy_powerstats(s, 5) )
        {
          v9 = &qword_9610;
          if ( !qword_9648 )
          {
            v11 = 0;
            v7 = 0;
            v12 = qword_9610;
            if ( !qword_9610 )
              goto LABEL_78;
            goto LABEL_56;
          }
          v7 = *(_QWORD *)(qword_9648 + 24);
          if ( *(_QWORD *)(qword_9648 + 8) > *(_QWORD *)(qword_9648 + 16) )
          {
            v10 = (__int64 (*)(void))arch_timer_read_counter;
            if ( *(_DWORD *)(arch_timer_read_counter - 4LL) != -1073338243 )
              __break(0x8228u);
            v11 = 0;
            v7 = v10() + v7 - *(_QWORD *)(qword_9648 + 8);
            v12 = qword_9610;
            if ( !qword_9610 )
              goto LABEL_78;
            goto LABEL_56;
          }
          goto LABEL_55;
        }
LABEL_31:
        result = 4294967170LL;
      }
      break;
    case 3:
      if ( (byte_9602 & 1) == 0 )
        sysmon_smem_init_slpi(v4);
      result = 4294967170LL;
      v6 = (_BYTE *)qword_9618;
      if ( qword_9618 && (unsigned __int64)qword_9618 <= 0xFFFFFFFFFFFFF000LL )
      {
        if ( !(unsigned int)copy_powerstats(s, 3) )
        {
          if ( qword_9650 )
          {
            v7 = *(_QWORD *)(qword_9650 + 24);
            if ( *(_QWORD *)(qword_9650 + 8) > *(_QWORD *)(qword_9650 + 16) )
            {
              v13 = (__int64 (*)(void))arch_timer_read_counter;
              if ( *(_DWORD *)(arch_timer_read_counter - 4LL) != -1073338243 )
                __break(0x8228u);
              v7 = v13() + v7 - *(_QWORD *)(qword_9650 + 8);
            }
          }
          else
          {
            v7 = 0;
          }
          v9 = &qword_9618;
          if ( qword_9660 )
          {
            v11 = *(_QWORD *)(qword_9660 + 24);
            if ( *(_QWORD *)(qword_9660 + 8) <= *(_QWORD *)(qword_9660 + 16) )
              goto LABEL_53;
            v17 = (__int64 (*)(void))arch_timer_read_counter;
            if ( *(_DWORD *)(arch_timer_read_counter - 4LL) != -1073338243 )
              __break(0x8228u);
            v15 = v17();
            v16 = qword_9660;
LABEL_52:
            v11 = v15 + v11 - *(_QWORD *)(v16 + 8);
LABEL_53:
            v12 = *v9;
            if ( !*v9 )
              goto LABEL_78;
            goto LABEL_56;
          }
LABEL_55:
          v11 = 0;
          v12 = *v9;
          if ( *v9 )
          {
LABEL_56:
            if ( (*v6 & 0xFE) == 0 )
              goto LABEL_140;
            v18 = *(_QWORD *)(v12 + 208);
            __isb(0xFu);
            StatusReg = _ReadStatusReg(CNTVCT_EL0);
            v20 = StatusReg < v18 ? ~v18 : -(__int64)v18;
            v21 = v20 + StatusReg;
            if ( v21 < 0x124F800 )
              goto LABEL_140;
            v22 = v21 / 0x124F800;
            if ( v7 / 0x124F800 >= s[65] )
              v23 = s[65];
            else
              v23 = 0;
            v24 = v7 / 0x124F800 - v23;
            v25 = v22 - v24;
            if ( v22 < v24 )
              v25 = 0;
            v26 = 0;
            if ( v11 >= 0x124F800 )
            {
              v27 = s[66];
              if ( v11 / 0x124F800 < s[66] )
                v27 = 0;
              v26 = v11 / 0x124F800 - v27;
            }
            if ( v26 - 1 >= v24 )
              v28 = 0;
            else
              v28 = v26;
            v29 = 0;
            if ( s[1] == s[99] )
            {
LABEL_139:
              v31 = &s[v29];
              v32 = s[66];
              s[65] += v24 - v28;
              v33 = v31[33] + v25;
              v34 = v31[67] + v26;
              v31[33] = v33;
              v31[67] = v34;
              s[66] = v32 + v26;
LABEL_140:
              memcpy(a2, s, 0x190u);
              result = 0;
              *a2 = (unsigned __int8)*v6;
              break;
            }
            if ( s[2] == s[99] )
            {
              v29 = 1;
              goto LABEL_139;
            }
            if ( s[3] == s[99] )
            {
              v29 = 2;
              goto LABEL_139;
            }
            if ( s[4] == s[99] )
            {
              v29 = 3;
              goto LABEL_139;
            }
            if ( s[5] == s[99] )
            {
              v29 = 4;
              goto LABEL_139;
            }
            if ( s[6] == s[99] )
            {
              v29 = 5;
              goto LABEL_139;
            }
            if ( s[7] == s[99] )
            {
              v29 = 6;
              goto LABEL_139;
            }
            if ( s[8] == s[99] )
            {
              v29 = 7;
              goto LABEL_139;
            }
            if ( s[9] == s[99] )
            {
              v29 = 8;
              goto LABEL_139;
            }
            if ( s[10] == s[99] )
            {
              v29 = 9;
              goto LABEL_139;
            }
            if ( s[11] == s[99] )
            {
              v29 = 10;
              goto LABEL_139;
            }
            if ( s[12] == s[99] )
            {
              v29 = 11;
              goto LABEL_139;
            }
            if ( s[13] == s[99] )
            {
              v29 = 12;
              goto LABEL_139;
            }
            if ( s[14] == s[99] )
            {
              v29 = 13;
              goto LABEL_139;
            }
            if ( s[15] == s[99] )
            {
              v29 = 14;
              goto LABEL_139;
            }
            if ( s[16] == s[99] )
            {
              v29 = 15;
              goto LABEL_139;
            }
            if ( s[17] == s[99] )
            {
              v29 = 16;
              goto LABEL_139;
            }
            if ( s[18] == s[99] )
            {
              v29 = 17;
              goto LABEL_139;
            }
            if ( s[19] == s[99] )
            {
              v29 = 18;
              goto LABEL_139;
            }
            if ( s[20] == s[99] )
            {
              v29 = 19;
              goto LABEL_139;
            }
            if ( s[21] == s[99] )
            {
              v29 = 20;
              goto LABEL_139;
            }
            if ( s[22] == s[99] )
            {
              v29 = 21;
              goto LABEL_139;
            }
            if ( s[23] == s[99] )
            {
              v29 = 22;
              goto LABEL_139;
            }
            if ( s[24] == s[99] )
            {
              v29 = 23;
              goto LABEL_139;
            }
            if ( s[25] == s[99] )
            {
              v29 = 24;
              goto LABEL_139;
            }
            if ( s[26] == s[99] )
            {
              v29 = 25;
              goto LABEL_139;
            }
            if ( s[27] == s[99] )
            {
              v29 = 26;
              goto LABEL_139;
            }
            if ( s[28] == s[99] )
            {
              v29 = 27;
              goto LABEL_139;
            }
            if ( s[29] == s[99] )
            {
              v29 = 28;
              goto LABEL_139;
            }
            if ( s[30] == s[99] )
            {
              v29 = 29;
              goto LABEL_139;
            }
            if ( s[31] == s[99] )
            {
              v29 = 30;
              goto LABEL_139;
            }
            if ( s[32] == s[99] )
            {
              v29 = 31;
              goto LABEL_139;
            }
            v30 = &unk_9AE3;
            goto LABEL_77;
          }
LABEL_78:
          result = 4294967274LL;
          break;
        }
        goto LABEL_31;
      }
      break;
    case 2:
      if ( (g_sysmon_stats & 1) == 0 )
        sysmon_smem_init_adsp(v4);
      result = 4294967170LL;
      v6 = (_BYTE *)qword_9608;
      if ( qword_9608 && (unsigned __int64)qword_9608 <= 0xFFFFFFFFFFFFF000LL )
      {
        if ( !(unsigned int)copy_powerstats(s, 2) )
        {
          if ( qword_9640 )
          {
            v7 = *(_QWORD *)(qword_9640 + 24);
            if ( *(_QWORD *)(qword_9640 + 8) > *(_QWORD *)(qword_9640 + 16) )
            {
              v8 = (__int64 (*)(void))arch_timer_read_counter;
              if ( *(_DWORD *)(arch_timer_read_counter - 4LL) != -1073338243 )
                __break(0x8228u);
              v7 = v8() + v7 - *(_QWORD *)(qword_9640 + 8);
            }
          }
          else
          {
            v7 = 0;
          }
          v9 = &qword_9608;
          if ( qword_9658 )
          {
            v11 = *(_QWORD *)(qword_9658 + 24);
            if ( *(_QWORD *)(qword_9658 + 8) <= *(_QWORD *)(qword_9658 + 16) )
              goto LABEL_53;
            v14 = (__int64 (*)(void))arch_timer_read_counter;
            if ( *(_DWORD *)(arch_timer_read_counter - 4LL) != -1073338243 )
              __break(0x8228u);
            v15 = v14();
            v16 = qword_9658;
            goto LABEL_52;
          }
          goto LABEL_55;
        }
        goto LABEL_31;
      }
      break;
    default:
      v30 = &unk_986A;
LABEL_77:
      printk(v30, "sysmon_subsystem_stats");
      goto LABEL_78;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
