_QWORD *__fastcall ucfg_dp_register_hdd_callbacks(__int64 a1, _QWORD *a2)
{
  _QWORD *result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  result = (_QWORD *)wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Eu);
  if ( !result )
    return (_QWORD *)qdf_trace_msg(
                       0x45u,
                       2u,
                       "%s: DP ctx is NULL",
                       v4,
                       v5,
                       v6,
                       v7,
                       v8,
                       v9,
                       v10,
                       v11,
                       "ucfg_dp_register_hdd_callbacks");
  result[47] = *a2;
  result[64] = a2[17];
  result[65] = a2[18];
  result[66] = a2[19];
  result[67] = a2[20];
  result[68] = a2[21];
  result[73] = a2[26];
  result[74] = a2[27];
  result[75] = a2[28];
  result[71] = a2[24];
  result[72] = a2[25];
  result[81] = a2[34];
  result[82] = a2[35];
  result[70] = a2[23];
  result[76] = a2[29];
  result[77] = a2[30];
  result[78] = a2[31];
  result[79] = a2[32];
  result[80] = a2[33];
  result[84] = a2[37];
  result[86] = a2[39];
  result[87] = a2[40];
  result[50] = a2[3];
  result[49] = a2[2];
  result[51] = a2[4];
  result[52] = a2[5];
  result[53] = a2[6];
  result[59] = a2[12];
  result[48] = a2[1];
  result[54] = a2[7];
  result[55] = a2[8];
  result[56] = a2[9];
  result[57] = a2[10];
  result[58] = a2[11];
  result[60] = a2[13];
  result[61] = a2[14];
  result[62] = a2[15];
  result[63] = a2[16];
  result[69] = a2[22];
  result[85] = a2[38];
  result[83] = a2[36];
  result[88] = a2[41];
  result[94] = a2[47];
  result[89] = a2[42];
  result[90] = a2[43];
  result[91] = a2[44];
  result[92] = a2[45];
  result[93] = a2[46];
  result[95] = a2[48];
  return result;
}
