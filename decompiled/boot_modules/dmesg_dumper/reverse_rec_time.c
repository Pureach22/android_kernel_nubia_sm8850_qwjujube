_QWORD *__fastcall reverse_rec_time(_QWORD *result)
{
  __int64 v1; // x9
  __int64 v2; // x10
  __int64 v3; // x8
  __int64 v4; // x8
  __int64 v5; // x8
  __int64 v6; // x8
  __int64 v7; // x8

  v1 = result[13];
  result[14] = result[12];
  result[15] = v1;
  v2 = result[11];
  result[12] = result[10];
  result[13] = v2;
  v3 = result[9];
  result[10] = result[8];
  result[11] = v3;
  v4 = result[7];
  result[8] = result[6];
  result[9] = v4;
  v5 = result[5];
  result[6] = result[4];
  result[7] = v5;
  v6 = result[3];
  result[4] = result[2];
  result[5] = v6;
  v7 = result[1];
  result[2] = *result;
  result[3] = v7;
  return result;
}
