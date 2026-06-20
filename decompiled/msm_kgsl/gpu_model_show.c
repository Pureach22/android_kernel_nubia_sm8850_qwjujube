__int64 __fastcall gpu_model_show(__int64 a1, __int64 a2, __int64 a3)
{
  char *gpu_model; // x0

  gpu_model = adreno_get_gpu_model(*(_QWORD *)(a1 + 152));
  return (int)scnprintf(a3, 4096, gpu_model);
}
