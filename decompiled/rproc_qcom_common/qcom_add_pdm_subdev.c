__int64 __fastcall qcom_add_pdm_subdev(__int64 a1, __int64 a2)
{
  int v2; // w8

  *(_QWORD *)(a2 + 48) = a1 + 56;
  v2 = *(_DWORD *)(a1 + 1160);
  *(_QWORD *)(a2 + 16) = pdm_notify_prepare;
  *(_DWORD *)(a2 + 56) = v2;
  *(_QWORD *)(a2 + 40) = pdm_notify_unprepare;
  return rproc_add_subdev(a1, a2);
}
