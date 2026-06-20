__int64 __fastcall kgsl_hw_fence_trigger_cpu(__int64 a1, __int64 a2)
{
  if ( (*(_QWORD *)(a1 + 1528) & 0x200) == 0
    && (unsigned int)__ratelimit(&kgsl_hw_fence_trigger_cpu__rs, "kgsl_hw_fence_trigger_cpu") )
  {
    _warn_printk("signaling hw fence via cpu without soccp powered up\n");
    __break(0x800u);
  }
  return synx_signal(kgsl_synx, *(unsigned int *)(a2 + 104), 2);
}
