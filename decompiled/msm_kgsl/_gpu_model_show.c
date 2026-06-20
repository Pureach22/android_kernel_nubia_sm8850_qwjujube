__int64 __fastcall gpu_model_show(__int64 a1, __int64 a2)
{
  char *gpu_model; // x0

  gpu_model = adreno_get_gpu_model(a1);
  return (int)scnprintf(a2, 4096, gpu_model);
}
