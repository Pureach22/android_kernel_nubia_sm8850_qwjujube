__int64 __fastcall synx_util_map_client_id_to_core(unsigned int a1)
{
  if ( a1 > 0xD )
    return 8;
  else
    return dword_25000[a1];
}
