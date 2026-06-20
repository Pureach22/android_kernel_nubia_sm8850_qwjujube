__int64 __fastcall msm_vidc_fence_deinit(__int64 result, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  *(_DWORD *)(result + 37840) = 0;
  *(_QWORD *)(result + 37848) = 0;
  *(_BYTE *)(result + 37680) = 0;
  *(_DWORD *)(result + 38016) = 0;
  *(_QWORD *)(result + 38024) = 0;
  *(_BYTE *)(result + 37856) = 0;
  *(_DWORD *)(result + 38192) = 0;
  *(_QWORD *)(result + 38200) = 0;
  *(_BYTE *)(result + 38032) = 0;
  *(_DWORD *)(result + 38368) = 0;
  *(_QWORD *)(result + 38376) = 0;
  *(_BYTE *)(result + 38208) = 0;
  *(_QWORD *)(result + 37808) = 0;
  *(_QWORD *)(result + 37816) = 0;
  *(_QWORD *)(result + 37984) = 0;
  *(_QWORD *)(result + 37992) = 0;
  *(_QWORD *)(result + 38160) = 0;
  *(_QWORD *)(result + 38168) = 0;
  *(_QWORD *)(result + 38336) = 0;
  *(_QWORD *)(result + 38344) = 0;
  if ( result )
  {
    if ( (msm_vidc_debug & 2) != 0 )
      return printk(&unk_80624, "high", result + 340, "msm_vidc_fence_deinit", a5);
  }
  return result;
}
