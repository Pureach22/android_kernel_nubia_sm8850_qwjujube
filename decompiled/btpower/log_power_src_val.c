__int64 log_power_src_val()
{
  __int64 v0; // x0
  __int64 v1; // x0
  __int64 result; // x0
  __int64 v3; // x8
  __int64 v4; // x20
  __int64 v5; // x21
  __int64 v6; // x20
  __int64 v7; // x21
  __int64 v8; // x20
  __int64 v9; // x21

  v0 = gpio_to_desc(*(unsigned int *)(pwr_data + 16));
  dword_13A20 = gpiod_get_raw_value(v0);
  v1 = gpio_to_desc(*(unsigned int *)(pwr_data + 8));
  result = gpiod_get_raw_value(v1);
  v3 = pwr_data;
  dword_13A1C = result;
  if ( *(int *)(pwr_data + 136) >= 1 )
  {
    v4 = 0;
    v5 = 0;
    do
    {
      result = set_pwr_srcs_status(*(_QWORD *)(v3 + 56) + v4, 0);
      v3 = pwr_data;
      ++v5;
      v4 += 48;
    }
    while ( v5 < *(int *)(pwr_data + 136) );
  }
  if ( *(int *)(v3 + 144) >= 1 )
  {
    v6 = 0;
    v7 = 0;
    do
    {
      result = set_pwr_srcs_status(*(_QWORD *)(v3 + 80) + v6, 2);
      v3 = pwr_data;
      ++v7;
      v6 += 48;
    }
    while ( v7 < *(int *)(pwr_data + 144) );
  }
  if ( *(int *)(v3 + 140) >= 1 )
  {
    v8 = 0;
    v9 = 0;
    do
    {
      result = set_pwr_srcs_status(*(_QWORD *)(v3 + 64) + v8, 1);
      v3 = pwr_data;
      ++v9;
      v8 += 48;
    }
    while ( v9 < *(int *)(pwr_data + 140) );
  }
  return result;
}
