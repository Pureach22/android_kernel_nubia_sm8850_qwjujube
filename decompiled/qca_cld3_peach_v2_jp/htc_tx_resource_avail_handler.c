__int64 __fastcall htc_tx_resource_avail_handler(__int64 result, unsigned __int8 a2)
{
  _DWORD *v2; // x19
  __int64 v3; // x20

  if ( *(_WORD *)(result + 12) && *(unsigned __int8 *)(result + 144) == a2 )
  {
    v2 = (_DWORD *)(result + 8);
LABEL_28:
    if ( (dword_B0B4 & 0x100) != 0 )
    {
      v3 = result;
      qdf_trace_msg(56, 2, "%s: HIF indicated more resources for pipe:%d\n", "htc_tx_resource_avail_handler", a2);
      result = v3;
    }
    return htc_try_send(result, v2, 0);
  }
  if ( *(_WORD *)(result + 340) && *(unsigned __int8 *)(result + 472) == a2 )
  {
    v2 = (_DWORD *)(result + 336);
    goto LABEL_28;
  }
  if ( *(_WORD *)(result + 668) && *(unsigned __int8 *)(result + 800) == a2 )
  {
    v2 = (_DWORD *)(result + 664);
    goto LABEL_28;
  }
  if ( *(_WORD *)(result + 996) && *(unsigned __int8 *)(result + 1128) == a2 )
  {
    v2 = (_DWORD *)(result + 992);
    goto LABEL_28;
  }
  if ( *(_WORD *)(result + 1324) && *(unsigned __int8 *)(result + 1456) == a2 )
  {
    v2 = (_DWORD *)(result + 1320);
    goto LABEL_28;
  }
  if ( *(_WORD *)(result + 1652) && *(unsigned __int8 *)(result + 1784) == a2 )
  {
    v2 = (_DWORD *)(result + 1648);
    goto LABEL_28;
  }
  if ( *(_WORD *)(result + 1980) && *(unsigned __int8 *)(result + 2112) == a2 )
  {
    v2 = (_DWORD *)(result + 1976);
    goto LABEL_28;
  }
  if ( *(_WORD *)(result + 2308) && *(unsigned __int8 *)(result + 2440) == a2 )
  {
    v2 = (_DWORD *)(result + 2304);
    goto LABEL_28;
  }
  if ( *(_WORD *)(result + 2636) && *(unsigned __int8 *)(result + 2768) == a2 )
  {
    v2 = (_DWORD *)(result + 2632);
    goto LABEL_28;
  }
  if ( (dword_B0B4 & 1) != 0 )
    return qdf_trace_msg(
             56,
             2,
             "%s: Invalid pipe indicated for TX resource avail : %d!\n",
             "htc_tx_resource_avail_handler",
             a2);
  return result;
}
