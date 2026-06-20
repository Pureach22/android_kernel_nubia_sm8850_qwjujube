__int64 __fastcall dwc3_msm_id_notifier(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x21
  int v6; // w3
  __int64 v7; // x0

  if ( a3 )
  {
    v3 = *(_QWORD *)(a1 - 40);
    if ( v3 )
    {
      dwc3_dbg_print(*(_QWORD *)(v3 + 1256), 0xFFu, "extcon idx", *(_DWORD *)(a1 - 32), (const char *)&unk_16A05);
      v6 = a2 == 0;
      if ( *(_DWORD *)(v3 + 752) != v6 )
      {
        v7 = *(_QWORD *)(v3 + 1256);
        *(_DWORD *)(v3 + 792) = *(_DWORD *)(a1 - 32);
        *(_DWORD *)(v3 + 752) = v6;
        dwc3_dbg_print(v7, 0xFFu, "id_state", v6, (const char *)&unk_16A05);
        queue_work_on(32, *(_QWORD *)(v3 + 640), v3 + 568);
      }
    }
  }
  return 0;
}
