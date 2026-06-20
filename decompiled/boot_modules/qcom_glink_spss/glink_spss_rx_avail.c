__int64 __fastcall glink_spss_rx_avail(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x9

  v1 = **(unsigned int **)(a1 + 56);
  v2 = **(unsigned int **)(a1 + 48);
  if ( (unsigned int)v1 >= (unsigned int)v2 )
    return (unsigned int)(v1 - v2);
  else
    return v1 - v2 + *(_QWORD *)a1;
}
