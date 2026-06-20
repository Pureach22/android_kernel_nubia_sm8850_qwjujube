__int64 qrtr_ns_remove()
{
  kthread_flush_worker(&unk_D990);
  kthread_stop(qword_D9F0);
  _module_get(*(_QWORD *)(*(_QWORD *)(qrtr_ns + 32) + 8LL));
  _module_get(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(qrtr_ns + 24) + 576LL) + 392LL));
  return sock_release(qrtr_ns);
}
