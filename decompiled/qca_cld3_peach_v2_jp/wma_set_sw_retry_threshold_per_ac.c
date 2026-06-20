__int64 __fastcall wma_set_sw_retry_threshold_per_ac(__int64 *a1, unsigned __int8 a2, _DWORD *a3)
{
  __int64 result; // x0
  unsigned int v7; // w21
  unsigned int v8; // w22
  unsigned int v9; // w4
  unsigned int v10; // w27
  unsigned int v11; // w23
  unsigned int v12; // w24
  unsigned int v13; // w25
  unsigned int v14; // w26

  if ( (unsigned int)_wma_validate_handle(a1, "wma_set_sw_retry_threshold_per_ac") )
    return 4;
  v8 = a3[6];
  v7 = a3[7];
  v10 = a3[13];
  v9 = a3[14];
  v11 = a3[8];
  v12 = a3[9];
  v14 = a3[11];
  v13 = a3[12];
  if ( !v9 || (result = wma_set_sw_retry_by_qos(a1, a2, 0, 0, v9), !(_DWORD)result) )
  {
    if ( !v10 || (result = wma_set_sw_retry_by_qos(a1, a2, 0, 1u, v10), !(_DWORD)result) )
    {
      if ( !v14 || (result = wma_set_sw_retry_by_qos(a1, a2, 0, 2u, v14), !(_DWORD)result) )
      {
        if ( !v13 || (result = wma_set_sw_retry_by_qos(a1, a2, 0, 3u, v13), !(_DWORD)result) )
        {
          if ( !v12 || (result = wma_set_sw_retry_by_qos(a1, a2, 1u, 0, v12), !(_DWORD)result) )
          {
            if ( !v11 || (result = wma_set_sw_retry_by_qos(a1, a2, 1u, 1u, v11), !(_DWORD)result) )
            {
              if ( !v8 || (result = wma_set_sw_retry_by_qos(a1, a2, 1u, 2u, v8), !(_DWORD)result) )
              {
                if ( v7 )
                  return wma_set_sw_retry_by_qos(a1, a2, 1u, 3u, v7);
                else
                  return 0;
              }
            }
          }
        }
      }
    }
  }
  return result;
}
