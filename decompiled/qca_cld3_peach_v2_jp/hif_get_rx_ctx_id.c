__int64 __fastcall hif_get_rx_ctx_id(unsigned int a1, __int64 a2)
{
  if ( (unsigned int)hif_napi_enabled(a2, 0xFFFFFFFFLL) )
    return a1 + 1;
  else
    return a1;
}
