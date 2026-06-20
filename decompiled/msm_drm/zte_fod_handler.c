__int64 __fastcall zte_fod_handler(__int64 a1, __int64 a2)
{
  int v3; // w20
  __int64 result; // x0
  __int64 v5; // x1
  __int64 v6; // x20

  v3 = a2;
  result = printk(&unk_236F48, a2);
  if ( v3 == 1 && (*(_BYTE *)(a1 + 2558) & 1) == 0 )
  {
    if ( (unsigned int)(*(_DWORD *)(a1 + 2220) - 1) <= 1 )
    {
      v5 = *(_QWORD *)(a1 + 2592);
      *(_BYTE *)(a1 + 2559) = 1;
      result = queue_work_on(32, v5, a1 + 2560);
    }
    if ( *(_DWORD *)(a1 + 2320) )
    {
      v6 = *(_QWORD *)(a1 + 2488);
      printk(&unk_2590DD, work2string[0]);
      result = queue_work_on(32, v6, a1 + 2456);
      *(_BYTE *)(a1 + 2448) = 1;
    }
  }
  return result;
}
