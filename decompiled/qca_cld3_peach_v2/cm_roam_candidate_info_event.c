__int64 __fastcall cm_roam_candidate_info_event(unsigned int *a1, unsigned __int8 a2)
{
  unsigned int v4; // w21
  __int64 v5; // x0
  unsigned int v6; // w10
  int v7; // w8
  unsigned int v8; // w10
  char v9; // w11
  __int16 v10; // w12
  int v11; // w8
  int v12; // w9
  unsigned int v13; // w12
  char v14; // w9
  __int64 result; // x0
  __int64 v16; // [xsp+0h] [xbp-40h] BYREF
  unsigned __int64 time_of_the_day_us; // [xsp+8h] [xbp-38h]
  __int64 v18; // [xsp+10h] [xbp-30h]
  __int64 v19; // [xsp+18h] [xbp-28h]
  __int64 v20; // [xsp+20h] [xbp-20h]
  unsigned __int64 v21; // [xsp+28h] [xbp-18h]
  unsigned __int64 v22; // [xsp+30h] [xbp-10h]
  __int64 v23; // [xsp+38h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  time_of_the_day_us = 0;
  v18 = 0;
  v16 = 0;
  qdf_mem_set(&v16, 0x38u, 0);
  v4 = *a1;
  HIWORD(v16) = 0;
  time_of_the_day_us = qdf_get_time_of_the_day_us();
  v5 = ktime_get();
  v18 = 1000LL * v4;
  v19 = v5 / 1000;
  qdf_mem_copy(&v16, (char *)a1 + 5, 6u);
  v6 = a1[9];
  v7 = *((unsigned __int8 *)a1 + 4);
  LOBYTE(v20) = 3;
  v8 = 1000 * v6;
  WORD2(v20) = a1[4];
  v9 = BYTE1(v20) & 0xFC;
  if ( v7 == 1 )
    v10 = 15;
  else
    v10 = 16;
  if ( v7 == 1 )
    ++v9;
  v11 = -a1[6];
  if ( v8 >= 0x989680 )
    v12 = 10000000;
  else
    v12 = v8;
  HIWORD(v20) = v10;
  v13 = a1[8];
  v22 = __PAIR64__(v12, v11);
  v14 = *((_BYTE *)a1 + 56);
  WORD1(v20) = a2;
  v21 = __PAIR64__(*((unsigned __int16 *)a1 + 6), v13);
  BYTE1(v20) = v9 | (2 * v14);
  result = host_diag_event_report_payload(3358, 56, &v16);
  _ReadStatusReg(SP_EL0);
  return result;
}
