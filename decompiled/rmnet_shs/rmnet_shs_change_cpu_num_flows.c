__int64 __fastcall rmnet_shs_change_cpu_num_flows(__int64 result, char a2)
{
  int v2; // w10
  int v3; // w10

  if ( (unsigned __int16)result > 7u )
  {
    ++qword_1A460;
  }
  else
  {
    v2 = cpu_num_flows[(unsigned __int16)result];
    if ( (a2 & 1) != 0 )
      v3 = v2 + 1;
    else
      v3 = v2 - 1;
    cpu_num_flows[(unsigned __int16)result] = v3;
  }
  return result;
}
