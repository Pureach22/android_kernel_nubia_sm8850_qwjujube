__int64 __fastcall rmnet_mem_nl_get_mem_stats(__int64 a1, __int64 a2)
{
  _QWORD v4[125]; // [xsp+8h] [xbp-3F8h] BYREF
  __int16 v5; // [xsp+3F0h] [xbp-10h]
  __int64 v6; // [xsp+3F8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  ++qword_8E20;
  memset(&v4[74], 0, 0x198u);
  v4[8] = rmnet_mem_id_gaveup[0];
  v4[9] = qword_8DC0;
  v4[10] = qword_8DC8;
  v4[11] = qword_8DD0;
  v4[12] = rmnet_mem_id_req[0];
  v4[13] = qword_8D40;
  v4[14] = qword_8D48;
  v4[15] = qword_8D50;
  v4[18] = qword_8D88;
  v4[19] = qword_8D90;
  v4[16] = rmnet_mem_id_recycled[0];
  v4[17] = qword_8D80;
  v4[24] = rmnet_mem_order_gaveup[0];
  v4[25] = qword_8DE0;
  v4[26] = qword_8DE8;
  v4[27] = qword_8DF0;
  v4[30] = qword_8DA8;
  v4[31] = qword_8DB0;
  v4[28] = rmnet_mem_order_recycled[0];
  v4[29] = qword_8DA0;
  v4[22] = qword_8D68;
  v4[23] = qword_8D70;
  v4[20] = rmnet_mem_order_requests[0];
  v4[21] = qword_8D60;
  v4[0] = max_pool_size;
  v4[1] = qword_1B0;
  v4[2] = cache_pool_size;
  v4[3] = qword_8CB0;
  v4[4] = static_pool_size;
  v4[5] = qword_8C60;
  v4[6] = target_pool_size;
  v4[7] = qword_1C0;
  v4[34] = qword_8F60;
  v4[35] = qword_8F68;
  v4[32] = rmnet_mem_pb_ind_max;
  v4[33] = qword_8F58;
  v4[38] = qword_8D08;
  v4[39] = qword_8D10;
  v4[36] = rmnet_mem_cache_adds[0];
  v4[37] = qword_8D00;
  v4[42] = qword_8D28;
  v4[43] = qword_8D30;
  v4[40] = rmnet_mem_cache_add_fails[0];
  v4[41] = qword_8D20;
  v4[56] = qword_8E58;
  v4[57] = qword_8E60;
  v4[44] = rmnet_mem_stats;
  v4[45] = qword_8E00;
  v4[48] = qword_8E18;
  v4[49] = qword_8E20;
  v4[46] = qword_8E08;
  v4[47] = qword_8E10;
  v4[52] = qword_8E38;
  v4[53] = qword_8E40;
  v4[50] = qword_8E28;
  v4[51] = qword_8E30;
  v4[54] = qword_8E48;
  v4[55] = qword_8E50;
  v4[70] = qword_8C38;
  v4[71] = qword_8C40;
  v4[72] = qword_8C48;
  v4[73] = qword_8C50;
  v4[66] = qword_8C18;
  v4[67] = qword_8C20;
  v4[69] = qword_8C30;
  v4[68] = qword_8C28;
  v4[62] = qword_8BF8;
  v4[63] = qword_8C00;
  v4[64] = qword_8C08;
  v4[65] = qword_8C10;
  v4[58] = qword_8E68;
  v4[59] = rmnet_mem_err;
  v4[60] = qword_8BE8;
  v4[61] = qword_8BF0;
  v5 = 1;
  if ( (rmnet_mem_send_msg_to_userspace(a2, (__int64)v4) & 0x80000000) != 0 )
    ++qword_8C00;
  _ReadStatusReg(SP_EL0);
  return 0;
}
