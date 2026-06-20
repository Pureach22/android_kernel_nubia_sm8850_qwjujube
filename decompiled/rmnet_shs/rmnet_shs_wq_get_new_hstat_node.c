__int64 rmnet_shs_wq_get_new_hstat_node()
{
  __int64 result; // x0
  __int64 v1; // x19

  result = _kmalloc_cache_noprof(rmnet_module_hook_perf_ingress, 2336, 336);
  if ( result )
  {
    *(_QWORD *)(result + 88) = 0;
    v1 = result;
    *(_QWORD *)(result + 316) = 0;
    *(_DWORD *)(result + 312) = -1;
    *(_BYTE *)(result + 328) = 0;
    *(_QWORD *)(result + 112) = 0;
    *(_QWORD *)(result + 120) = 0;
    *(_QWORD *)(result + 128) = 0;
    *(_QWORD *)(result + 136) = 0;
    *(_QWORD *)(result + 144) = 0;
    *(_QWORD *)(result + 152) = 0;
    *(_QWORD *)(result + 160) = 0;
    *(_QWORD *)(result + 168) = 0;
    *(_QWORD *)(result + 200) = 0;
    *(_QWORD *)(result + 208) = 0;
    *(_QWORD *)(result + 216) = 0;
    *(_QWORD *)(result + 224) = 0;
    *(_QWORD *)(result + 232) = 0;
    *(_QWORD *)(result + 240) = 0;
    *(_QWORD *)(result + 248) = 0;
    *(_QWORD *)(result + 264) = 0;
    *(_QWORD *)(result + 272) = 0;
    *(_QWORD *)(result + 280) = 0;
    *(_QWORD *)(result + 288) = 0;
    *(_QWORD *)(result + 296) = 0;
    *(_QWORD *)(result + 304) = 0;
    *(_QWORD *)(result + 56) = result + 56;
    *(_QWORD *)(result + 64) = result + 56;
    *(_BYTE *)(result + 327) = 0;
    *(_BYTE *)(result + 325) = 0;
    *(_WORD *)(result + 325) = 1;
    *(_BYTE *)(result + 327) = 1;
    *(_QWORD *)(result + 72) = result + 72;
    *(_QWORD *)(result + 80) = result + 72;
    *(_QWORD *)(result + 56) = result + 56;
    *(_QWORD *)(result + 64) = result + 56;
    rmnet_shs_hstat_tbl_add(result);
    return v1;
  }
  else
  {
    ++qword_1A400;
  }
  return result;
}
