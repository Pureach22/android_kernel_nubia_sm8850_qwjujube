__int64 __fastcall cam_cci_i2c_write_continuous_table(__int64 a1, __int64 a2, char a3)
{
  if ( a3 == 1 || a3 == 2 )
    return cam_cci_i2c_write_table_cmd(a1, a2);
  else
    return 0;
}
