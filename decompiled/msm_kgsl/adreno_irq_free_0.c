__int64 __fastcall adreno_irq_free_0(__int64 result)
{
  __int64 v1; // x19

  if ( *(_DWORD *)(result + 20888) | *(_DWORD *)(result + 8832) )
  {
    v1 = result;
    result = devm_free_irq(*(_QWORD *)(result + 11168) + 16LL);
    *(_DWORD *)(v1 + 20888) = 0;
    *(_DWORD *)(v1 + 8832) = 0;
  }
  return result;
}
