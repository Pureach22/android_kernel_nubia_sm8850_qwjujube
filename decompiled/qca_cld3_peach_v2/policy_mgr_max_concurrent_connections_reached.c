_BYTE *__fastcall policy_mgr_max_concurrent_connections_reached(__int64 a1)
{
  _BYTE *result; // x0

  result = (_BYTE *)policy_mgr_get_context(a1);
  if ( result )
    return (_BYTE *)((unsigned __int8)result[2202] <= (unsigned int)(unsigned __int8)(result[1004]
                                                                                    + result[1003]
                                                                                    + result[1002]
                                                                                    + result[1001]
                                                                                    + result[1000]
                                                                                    + result[999]
                                                                                    + result[998]
                                                                                    + result[997]
                                                                                    + result[996]
                                                                                    + result[995]
                                                                                    + result[994]
                                                                                    + result[993]
                                                                                    + result[992]
                                                                                    + result[991]
                                                                                    + result[990]
                                                                                    + result[989]));
  return result;
}
