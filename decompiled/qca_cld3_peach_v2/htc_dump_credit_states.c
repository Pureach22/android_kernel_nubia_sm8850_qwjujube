__int64 __fastcall htc_dump_credit_states(__int64 result)
{
  __int64 v1; // x19
  __int64 i; // x27

  v1 = result;
  for ( i = 0; i != 2952; i += 328 )
  {
    if ( *(_WORD *)(v1 + i + 12) )
    {
      if ( (_WORD)dword_B804 )
      {
        result = qdf_trace_msg(
                   56,
                   2,
                   "%s: --- EP : %d  service_id: 0x%X    --------------\n",
                   "htc_dump_credit_states",
                   *(_DWORD *)(v1 + i + 8),
                   *(unsigned __int16 *)(v1 + i + 12));
        if ( (_WORD)dword_B804 )
        {
          result = qdf_trace_msg(
                     56,
                     2,
                     "%s:  TxCredits          : %d\n",
                     "htc_dump_credit_states",
                     *(_DWORD *)(v1 + i + 296));
          if ( (_WORD)dword_B804 )
          {
            result = qdf_trace_msg(
                       56,
                       2,
                       "%s:  TxCreditSize       : %d\n",
                       "htc_dump_credit_states",
                       *(_DWORD *)(v1 + i + 300));
            if ( (_WORD)dword_B804 )
            {
              result = qdf_trace_msg(
                         56,
                         2,
                         "%s:  TxCreditsPerMaxMsg : %d\n",
                         "htc_dump_credit_states",
                         *(_DWORD *)(v1 + i + 304));
              if ( (_WORD)dword_B804 )
              {
                result = qdf_trace_msg(
                           56,
                           2,
                           "%s:  TxQueueDepth       : %d\n",
                           "htc_dump_credit_states",
                           *(_DWORD *)(v1 + i + 128));
                if ( (_WORD)dword_B804 )
                  result = qdf_trace_msg(
                             56,
                             2,
                             "%s: ----------------------------------------\n",
                             "htc_dump_credit_states");
              }
            }
          }
        }
      }
    }
  }
  return result;
}
