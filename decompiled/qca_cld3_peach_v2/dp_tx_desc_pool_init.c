__int64 __fastcall dp_tx_desc_pool_init(__int64 a1, unsigned int a2, unsigned int a3, char a4)
{
  __int64 v8; // x23
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  const char *v17; // x2
  __int64 v18; // x23
  _DWORD *v19; // x9
  __int64 result; // x0

  if ( (unsigned __int8)a2 >= 7u )
  {
    __break(0x5512u);
    JUMPOUT(0x5769B8);
  }
  v8 = a1 + 296LL * (unsigned __int8)a2;
  if ( (unsigned int)qdf_mem_multi_page_link(*(_QWORD *)(a1 + 24), (unsigned __int16 *)(v8 + 2320), 0x100u, a3, 1) )
  {
    v17 = "%s: invalid tx desc allocation -overflow num link";
  }
  else
  {
    v18 = v8 + 2304;
    v19 = *(_DWORD **)(a1 + 1352);
    *(_QWORD *)(v18 + 8) = **(_QWORD **)(v18 + 32);
    if ( *(v19 - 1) != -181162185 )
      __break(0x8229u);
    result = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD))v19)(a1, a3, a2, a4 & 1);
    if ( !(_DWORD)result )
    {
      *(_WORD *)v18 = 256;
      return result;
    }
    v17 = "%s: initialization per target failed";
  }
  qdf_trace_msg(0x45u, 2u, v17, v9, v10, v11, v12, v13, v14, v15, v16, "dp_tx_desc_pool_init");
  return 5;
}
